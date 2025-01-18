#pragma once
//widgets
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QRadioButton>

//obs settings ui
#include "ui_OBSBasicSettings.h"
#include <vector>

namespace Ui {
static class AudioExpander {
public:
	static QSpinBox *numOfChannels;
	static std::vector<QPointer<QCheckBox>> simpleOutRecTracks;
	static std::vector<QPointer<QRadioButton>> simpleFlvTracks;
	static std::vector<QPointer<QRadioButton>> advOutTracks;
	static std::vector<QPointer<QCheckBox>> advOutMultiTracks;
	static std::vector<QPointer<QCheckBox>> advOutRecTracks;
	static std::vector<QPointer<QRadioButton>> flvTracks;
	static std::vector<QPointer<QCheckBox>> advOutFFTracks;
	static void setupUI(QDialog *OBSBasicSettings, Ui::Ui_OBSBasicSettings *instance);
	static void HookWidgets(Ui::OBSBasicSettings *instance);
	template<class OBSBasicSettings, typename Widget, typename WidgetParent, typename... SignalArgs, typename... SlotArgs>
	void redirect(Ui::OBSBasicSettings *instance, Widget *widget,
					 void (WidgetParent::*signal)(SignalArgs...),
					 void (OBSBasicSettings::*slot)(SlotArgs...));
};
template<class OBSBasicSettings, typename Widget, typename WidgetParent, typename... SignalArgs, typename... SlotArgs>
inline void AudioExpander::redirect(Ui::OBSBasicSettings *instance, Widget *widget,
				    void (WidgetParent::*signal)(SignalArgs...),
				    void (OBSBasicSettings::*slot)(SlotArgs...))
{
	instance->ReHookWidget(widget, signal, slot);
}
} // namespace Ui
