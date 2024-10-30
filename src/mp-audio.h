#ifndef __MP_AUDIO_H__
#define __MP_AUDIO_H__

#include <iostream>

namespace MPWAV {

class mpAudio {
public:
    mpAudio(int32_t sampleRate);
    virtual ~mpAudio();


private:
    int32_t _sampleRate = 0;
    bool    _use        = false;

public:
    void setProcess(bool use) {
        _use = use;
    }
    bool apply(const float* input, float* output, int32_t length);

};

};

#endif // __MP_AUDIO_H__