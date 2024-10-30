#include <stdio.h>
#include <iostream>
#include <portaudio.h>
#include <mp-audio.h>

using namespace MPWAV;

struct ThreadData {
    mpAudio* _processor;
};

constexpr int SAMPLE_RATE = 16000;
constexpr int FRAMES_PER_BUFFER = 256; // 한 번에 처리할 프레임 수

static int audioCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData) {

    float* output = static_cast<float*>(outputBuffer);
    const float *input = static_cast<const float*>(inputBuffer);
    ThreadData* td = static_cast<ThreadData*>(userData);
    td->_processor->apply(input, output, framesPerBuffer);

    return paContinue; // 계속 스트리밍
}

int main()
{
    mpAudio processor(SAMPLE_RATE);
    PaError err;
    ThreadData* td = new ThreadData();
    td->_processor = &processor;
    err = Pa_Initialize();
    if (err != paNoError) {
        std::cerr << "PortAudio Error: " << Pa_GetErrorText(err) << std::endl;
        return -1;
    }

    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream,
                                1, // 입력 채널 수
                                1, // 출력 채널 수
                                paFloat32, // 샘플 포맷
                                SAMPLE_RATE,
                                FRAMES_PER_BUFFER,
                                audioCallback,
                                td); // userData

    if (err != paNoError) {
        std::cerr << "PortAudio Error: " << Pa_GetErrorText(err) << std::endl;
        return -1;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        std::cerr << "PortAudio Error: " << Pa_GetErrorText(err) << std::endl;
        return -1;
    }

    std::cout << "Press q to stop the sound..." << std::endl;
    while (true) {
        char input;
        std::cin.get(input);
        if (input == 'q') {
            break;
        }
        if (input == '1') {
            processor.setProcess(true);
        }
        if (input == '2') {
            processor.setProcess(false);
        }
    }    


    err = Pa_StopStream(stream);
    if (err != paNoError) {
        std::cerr << "PortAudio Error: " << Pa_GetErrorText(err) << std::endl;
        return -1;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        std::cerr << "PortAudio Error: " << Pa_GetErrorText(err) << std::endl;
        return -1;
    }

    Pa_Terminate();
    return 0;
}
