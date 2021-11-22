#pragma once

// Triggers a garbage collection before every allocation.
//#define DEBUG_STRESS_GC
// Prints information about garbage collection
//#define DEBUG_LOG_GC

// Prevents duplicates in generated constant vectors. Decreases memory usage while
// increasing compilation time. May decrease VM performance.
//#define COMPRESS_CONSTANTS

// Values always store whether they are an object or not. With this define,
// values will always store their exact type. May be used in the future.
// #define COMPLETE_TYPING
