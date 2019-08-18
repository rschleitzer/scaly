pub trait Disposable {
    fn dispose(&self);
}

pub trait Stream: Disposable {
    fn read_byte(&self) -> i32;
    fn write_byte(&self, u8);
}
