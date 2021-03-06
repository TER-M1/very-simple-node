#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;
const unsigned kRenderQuantumFrames = 128;
const unsigned kBytesPerChannel = kRenderQuantumFrames * sizeof(float);

class ProcessorPerf
{
public:
    ProcessorPerf() {}
    void processPerf(uintptr_t input_ptr, uintptr_t output_ptr, int channel_count)
    {
        float *input_buffer = reinterpret_cast<float *>(input_ptr);
        float *output_buffer = reinterpret_cast<float *>(output_ptr);

        // Bypasses the data. By design, the channel count will always be the same
        // for |input_buffer| and |output_buffer|.
        for (unsigned channel = 0; channel < channel_count; ++channel)
        {
            output_buffer = output_buffer + channel * kRenderQuantumFrames;
            input_buffer = input_buffer + channel * kRenderQuantumFrames;
            memcpy(output_buffer, input_buffer, kBytesPerChannel);
        }
    }
};

EMSCRIPTEN_BINDINGS(CLASS_ProcessorPerf)
{
    class_<ProcessorPerf>("ProcessorPerf")
        .constructor()
        .function("processPerf", &ProcessorPerf::processPerf, allow_raw_pointers());
}