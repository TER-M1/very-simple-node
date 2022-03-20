# FLAGS =  -lembind -o compiled_processor_perf.js processor-perf.cpp --post-js ./mod.js -s ENVIRONMENT="shell"
# CC = emcc


DEPS = processor-perf.cpp

build: $(DEPS)
	@emcc --bind -O1 \
	  -s WASM=1 \
		-s BINARYEN_ASYNC_COMPILATION=0 \
		-s SINGLE_FILE=1 \
		-o compiled_processor_perf.js processor-perf.cpp \
		--post-js ./mod.js \
		-s ENVIRONMENT="shell"

clean:
	@rm -f compiled_processor_perf.js