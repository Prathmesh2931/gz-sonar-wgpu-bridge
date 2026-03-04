#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__

float get_sonar_intensity_at_range(float range) noexcept;

#ifdef __clang__
#pragma clang diagnostic pop
#endif // __clang__
