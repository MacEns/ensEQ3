/*
  ==============================================================================

    KnobSlider.cpp
    Created: 2 Nov 2021 11:55:51am
    Author:  Mac Ens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "KnobSlider.h"
#include "KnobSliderLookAndFeel.h"

//==============================================================================
KnobSlider::KnobSlider(juce::RangedAudioParameter& rap, const juce::String& unitSuffix, bool isLog) :
	juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
				juce::Slider::TextEntryBoxPosition::NoTextBox),
	param(&rap),
	suffix(unitSuffix),
	isLogSlider(isLog)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
	knobSliderLookAndFeel.setLogSlider(isLog);
	setLookAndFeel(&knobSliderLookAndFeel);

}// KnobSlider()

KnobSlider::~KnobSlider()
{
	setLookAndFeel(nullptr);
}

void KnobSlider::mouseDown(const juce::MouseEvent& event)
{
	juce::Slider::mouseDown(event);
	setMouseCursor(juce::MouseCursor::NoCursor);
	mousePosition = juce::Desktop::getMousePosition();
}

void KnobSlider::mouseUp(const juce::MouseEvent& event)
{
	juce::Slider::mouseUp(event);
	juce::Desktop::setMousePosition(mousePosition);
	setMouseCursor(juce::MouseCursor::NormalCursor);
}

void KnobSlider::paint(juce::Graphics &g)
{
	using namespace juce;
	
	auto startAng = degreesToRadians(180.f+45.f);
	auto endAng = degreesToRadians(180.f-45.f) + MathConstants<float>::twoPi;
	auto range = getRange();
	auto sliderBounds = getSliderBounds();
	
	
//	 //Bounding Boxes around knobs
//		g.setColour(Colours::blue);
//		g.drawRect(getLocalBounds());
//
//		g.setColour(Colours::yellow);
//		g.drawRect(sliderBounds);
//	
	getLookAndFeel().drawRotarySlider(g,
									  sliderBounds.getX(),
									  sliderBounds.getY(),
									  sliderBounds.getWidth(),
									  sliderBounds.getHeight(),
									  jmap(getValue(), range.getStart(), range.getEnd(), 0.0, 1.0),
									  startAng,
									  endAng,
									  *this);
	
	auto center = sliderBounds.toFloat().getCentre();
	auto radius = sliderBounds.getWidth() * 0.5f;
	
	g.setColour(Colours::black);
	g.setFont(getTextHeight());
	
	auto numChoices = labels.size();
	for( int i = 0; i < numChoices; ++i )
	{
		auto pos = labels[i].pos;
		jassert(0.f <= pos);
		jassert(pos <= 1.f);
		
		auto ang = jmap(pos, 0.f, 1.f, startAng, endAng);
		
		auto c = center.getPointOnCircumference(radius + 1, ang);
		
		Rectangle<float> r;
		auto str = labels[i].label;
		r.setSize(g.getCurrentFont().getStringWidth(str), getTextHeight());
		r.setCentre(c);
		r.setY(r.getY() + getTextHeight());
		
		g.drawFittedText(str, r.toNearestInt(), juce::Justification::centred, 1);
	}// for
}// paint()

juce::Rectangle<int> KnobSlider::getSliderBounds() const
{
	auto bounds = getLocalBounds();
	
	auto size = juce::jmin(bounds.getWidth(), bounds.getHeight());
	
	size -= getTextHeight()*2;
	
	juce::Rectangle<int> r;
	r.setSize(size, size);
	r.setCentre(bounds.getCentreX(), 0);
	r.setY(2);
	
	return r;
}// getSliderBounds()

//void KnobSlider::resized()
//{
//    // This method is where you should set the bounds of any child
//    // components that your component contains..
//
//}
