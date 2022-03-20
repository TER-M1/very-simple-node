#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

class ProcessorPerf {
    public:
        ProcessorPerf() {}
        void processPerf(float* input, float* output, int channel) {
            for (int i = 0; i < channel; i++) {
                output[i] = input[i];
            }
        }
};

EMSCRIPTEN_BINDINGS(CLASS_ProcessorPerf) {
    class_<ProcessorPerf>("ProcessorPerf")
        .constructor()
        .function("processPerf", &ProcessorPerf::processPerf, allow_raw_pointers());
}