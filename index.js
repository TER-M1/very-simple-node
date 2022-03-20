const audioUrl = "sound.mp3";
const playButton = document.querySelector('#play');

(async () => {

    let decodedAudioBuffer;
    let audioArrayBuffer;

    var contexteAudio = new(window.AudioContext || window.webkitAudioContext)();
    contexteAudio.audioWorklet.addModule("processor.js");

    const response = await fetch("./BasketCaseGreendayriffDI.mp3");
    audioArrayBuffer = await response.arrayBuffer();
    decodedAudioBuffer = await contexteAudio.decodeAudioData(audioArrayBuffer);

    playButton.disabled = false;
    playButton.onclick = () => play(decodedAudioBuffer);

    function play(audioBuffer) {
        const node = new SimpleNode(contexteAudio);
        const source = contexteAudio.createBufferSource();
        source.buffer = audioBuffer;
        source.connect(node).connect(contexteAudio.destination);
        source.start();
    }
})();


class SimpleNode extends AudioWorkletNode {
    /**
    * @param {BaseAudioContext} context
    */
    constructor(context) {
        super(context, "simple-processor");
    }
}
