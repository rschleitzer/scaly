use containers::hashset::Hash;
use containers::hashset::HashPrimeHelper;
use containers::array::Array;
use containers::list::List;
use containers::reference::Ref;
use containers::vector::Vector;
use memory::page::Page;
use memory::region::Region;

#[derive(Copy, Clone)]
pub struct HashMap<K: Hash<K> + Copy> {
    slots: Ref<Vector<Ref<List<Slot<K>>>>>,
}

impl<K: Hash<K> + Copy> HashMap<K> {
    pub fn from_vector(_pr: &Region, _rp: *mut Page, vector: Ref<Vector<K>>) -> Ref<HashMap<K>> {
        let _r = Region::create(_pr);
        let hash_size = HashPrimeHelper::get_prime(vector.length);
        let mut array: Ref<Array<Ref<List<Slot<K>>>>> = Ref::new(_r.page, Array::new());
        for _ in 0..hash_size {
            array.add(Ref::new(_r.page, List::new()));
        }
        let slots = Ref::new(_rp, Vector::from_array(_rp, array));
        let mut hash_map = Ref::new(_rp, HashMap { slots: slots });
        hash_map.initialize_from_vector(vector);
        hash_map
    }

    fn initialize_from_vector(&mut self, vector: Ref<Vector<K>>) {
        for value in vector.iter() {
            self.add(value);
        }
    }

    fn add(&mut self, value: &K) {
        let hash_code = value.hash();
        let slot_number = hash_code % self.slots.length;
        let mut slot_list = self.slots[slot_number];
        for slot in slot_list.get_iterator() {
            if value.equals(&slot.value) {
                return;
            }
        }

        slot_list.add(Slot {
            hash_code: hash_code,
            value: *value,
        });
    }

    pub fn contains(&self, value: K) -> bool {
        for slot in self.slots[value.hash() % self.slots.length].get_iterator() {
            if value.equals(&slot.value) {
                return true;
            }
        }

        false
    }
}

#[derive(Copy, Clone)]
struct Slot<K: Copy> {
    value: K,
    hash_code: usize,
}

#[test]
fn test_hash_map() {
    use containers::String;
    use memory::Heap;
    use memory::Page;
    use memory::Region;
    use memory::StackBucket;
    let mut heap = Heap::create();
    let root_stack_bucket = StackBucket::create(&mut heap);
    let root_page = Page::get(root_stack_bucket as usize);
    let _r = Region::create_from_page(root_page);
    let keywords = HashMap::from_vector(
        &_r,
        _r.page,
        Ref::new(
            _r.page,
            Vector::from_raw_array(
                _r.page,
                &[
                    String::from_string_slice(_r.page, "using"),
                    String::from_string_slice(_r.page, "namespace"),
                    String::from_string_slice(_r.page, "typedef"),
                ],
            ),
        ),
    );

    assert_eq!(
        (*keywords).contains(String::from_string_slice(_r.page, "using")),
        true
    );
    assert_eq!(
        (*keywords).contains(String::from_string_slice(_r.page, "namespace")),
        true
    );
    assert_eq!(
        (*keywords).contains(String::from_string_slice(_r.page, "typedef")),
        true
    );
    assert_eq!(
        (*keywords).contains(String::from_string_slice(_r.page, "nix")),
        false
    );
}
