//import Module from "./compiled_processor_perf.js";

// TODO : J'arrive pas a importer le module

class SimpleProcessor extends AudioWorkletProcessor {
    constructor() {
        super();
        
        //this._processorPerf = new Module.ProcessorPerf();
    }

    process(inputs, outputs, parameters) {
        console.log("je suis dans le process");

        const input = inputs[0];
        const output = outputs[0];
        
        for (let channel = 0; channel < input.length; ++channel) {
            const inputChannel = input[channel];
            const outputChannel = output[channel];

            for (let i = 0; i < inputChannel.length; ++i) {
                //outputChannel[i] = Module.processPerf(inputChannel[i]);
                outputChannel[i] = inputChannel[i] + 1;
            }
        }

        return true;
    }
}

registerProcessor("simple-processor", SimpleProcessor);