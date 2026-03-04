#[cxx::bridge]
mod ffi {
    extern "Rust" {
        fn get_sonar_intensity_at_range(range: f32) -> f32;
    }
}

// The #[no_mangle] and extern "C" are the magic keys for the linker
#[no_mangle]
pub extern "C" fn get_sonar_intensity_at_range(range: f32) -> f32 {
    println!("Rust Engine: Computing intensity for range {}m...", range);
    if range < 0.1 { return 0.0; }
    1.0 / (range * range)
}