/*
  ==============================================================================

    SlidingToggleWithLight.h
    Created: 5 Nov 2021 9:32:44pm
    Author:  Mac Ens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SlidingToggleLNF.h"

//==============================================================================
/*
*/
class SlidingToggleWithLight  : public juce::ToggleButton
{
public:
    SlidingToggleWithLight();
    ~SlidingToggleWithLight() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlidingToggleWithLight)
	
};
