#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

class ProcessorPerf {
    public:
        ProcessorPerf() {}
        float processPerf(float input) {
            return input + 1;
        }
};

EMSCRIPTEN_BINDINGS(CLASS_ProcessorPerf) {
    class_<ProcessorPerf>("ProcessorPerf")
        .constructor()
        .function("processPerf", &ProcessorPerf::processPerf, allow_raw_pointers());
}