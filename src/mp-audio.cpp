#include "mp-audio.h"
#include <cmath>
#include <cstring>
// #include <algorithm>

using namespace MPWAV;


mpAudio::mpAudio(int32_t sampleRate)
{
    _sampleRate = sampleRate;
}

mpAudio::~mpAudio()
{
}

bool mpAudio::apply(const float* input, float* output, int32_t length)
{
    const float FREQUENCY = 440.0f; // 440 Hz
    const float AMPLITUDE = 0.5f; // 최대 진폭 (float 32)
    static float phase = 0.0f; // 위상 초기화

    if (_use) {
        // 입력음성 처리...
        for (unsigned long i = 0; i < length; ++i) {
            output[i] = input[i] + AMPLITUDE * std::sin(phase); // 사인파 생성
            phase += (2.0f * M_PI * FREQUENCY) / _sampleRate;

            // 주파수가 2PI로 넘치면 다시 0으로
            if (phase >= 2.0f * M_PI) {
                phase -= 2.0f * M_PI;
            }
        }
    }
    else {
        std::memcpy(output, input, length * sizeof(float));
    }

    return true;
}