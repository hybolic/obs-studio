#include "__AudioExpander.h"

void setupUI(QDialog *OBSBasicSettings, Ui::Ui_OBSBasicSettings *instance)
{
	//initialiser
	QSizePolicy sizePolicy9(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
	sizePolicy9.setHorizontalStretch(0);
	sizePolicy9.setVerticalStretch(0);

	for (uchar count = 0; count < 32; count++) {
		QPointer<QCheckBox> simpleOutRecTrack = new QCheckBox(instance->simpleRecTracks);

		simpleOutRecTrack->setObjectName("simpleOutRecTrack" + (count + 1));
		sizePolicy9.setHeightForWidth(simpleOutRecTrack->sizePolicy().hasHeightForWidth());
		simpleOutRecTrack->setSizePolicy(sizePolicy9);
		simpleOutRecTrack->setText(QString::fromUtf8("" + (count + 1)));
		if (Ui::AudioExpander::simpleOutRecTracks.size() > 1)
			QWidget::setTabOrder(Ui::AudioExpander::simpleOutRecTracks.back(), simpleOutRecTrack);
		Ui::AudioExpander::simpleOutRecTracks.push_back(simpleOutRecTrack);
	}
	instance->simpleOutRecTrack1 = Ui::AudioExpander::simpleOutRecTracks[0];
	instance->simpleOutRecTrack2 = Ui::AudioExpander::simpleOutRecTracks[1];
	instance->simpleOutRecTrack3 = Ui::AudioExpander::simpleOutRecTracks[2];
	instance->simpleOutRecTrack4 = Ui::AudioExpander::simpleOutRecTracks[3];
	instance->simpleOutRecTrack5 = Ui::AudioExpander::simpleOutRecTracks[4];
	instance->simpleOutRecTrack6 = Ui::AudioExpander::simpleOutRecTracks[5];
	//add tab from simpleOutCustom to first index of array
	QWidget::setTabOrder(instance->simpleOutCustom, Ui::AudioExpander::simpleOutRecTracks[0]);
	//add tab from last index of array to simpleOutPath
	QWidget::setTabOrder(Ui::AudioExpander::simpleOutRecTracks.back(), instance->simpleOutputPath);

	for (uchar count = 0; count < 32; count++) {
		QPointer<QRadioButton> simpleFlvTrack = new QRadioButton(instance->simpleRecTracks);
		simpleFlvTrack->setObjectName("simpleFlvTrack" + (count + 1));
		sizePolicy9.setHeightForWidth(simpleFlvTrack->sizePolicy().hasHeightForWidth());
		simpleFlvTrack->setSizePolicy(sizePolicy9);
		simpleFlvTrack->setChecked(true);
		instance->horizontalLayoutSimpleFLVTracks->addWidget(simpleFlvTrack);
		simpleFlvTrack->setText(
			QCoreApplication::translate("OBSBasicSettings", "" + (count + 1), nullptr));
		Ui::AudioExpander::simpleFlvTracks.push_back(simpleFlvTrack);
	}

	instance->simpleFlvTrack1 = Ui::AudioExpander::simpleFlvTracks[0];
	instance->simpleFlvTrack2 = Ui::AudioExpander::simpleFlvTracks[1];
	instance->simpleFlvTrack3 = Ui::AudioExpander::simpleFlvTracks[2];
	instance->simpleFlvTrack4 = Ui::AudioExpander::simpleFlvTracks[3];
	instance->simpleFlvTrack5 = Ui::AudioExpander::simpleFlvTracks[4];
	instance->simpleFlvTrack6 = Ui::AudioExpander::simpleFlvTracks[5];

	for (uchar count = 0; count < 32; count++) {
		QPointer<QRadioButton> advOutTrack = new QRadioButton(instance->streamSingleTracks);
		advOutTrack->setObjectName("advOutTrack" + (count + 1));
		advOutTrack->setText(QString::fromUtf8("" + (count + 1)));
		instance->horizontalLayout_7->addWidget(advOutTrack);
		if (Ui::AudioExpander::advOutTracks.size() > 1)
			QWidget::setTabOrder(Ui::AudioExpander::advOutTracks.back(), advOutTrack);
		Ui::AudioExpander::advOutTracks.push_back(advOutTrack);
	}

	instance->advOutTrack1 = Ui::AudioExpander::advOutTracks[0];
	instance->advOutTrack1 = Ui::AudioExpander::advOutTracks[1];
	instance->advOutTrack1 = Ui::AudioExpander::advOutTracks[2];
	instance->advOutTrack1 = Ui::AudioExpander::advOutTracks[3];
	instance->advOutTrack1 = Ui::AudioExpander::advOutTracks[4];
	instance->advOutTrack1 = Ui::AudioExpander::advOutTracks[5];

	QWidget::setTabOrder(instance->advOutTabs, Ui::AudioExpander::advOutTracks[0]);

	for (uchar count = 0; count < 32; count++) {
		QPointer<QCheckBox> advOutMultiTrack = new QCheckBox(instance->streamMultiTracks);
		advOutMultiTrack->setObjectName("advOutMultiTrack" + (count + 1));
		advOutMultiTrack->setText(QString::fromUtf8("" + (count + 1)));

		instance->horizontalLayout_multitrack->addWidget(advOutMultiTrack);
		if (Ui::AudioExpander::advOutMultiTracks.size() > 1)
			QWidget::setTabOrder(Ui::AudioExpander::advOutMultiTracks.back(), advOutMultiTrack);
		Ui::AudioExpander::advOutMultiTracks.push_back(advOutMultiTrack);
	}

	instance->advOutMultiTrack1 = Ui::AudioExpander::advOutMultiTracks[0];
	QWidget::setTabOrder(Ui::AudioExpander::advOutTracks.back(), instance->advOutMultiTrack1);
	instance->advOutMultiTrack2 = Ui::AudioExpander::advOutMultiTracks[1];
	instance->advOutMultiTrack3 = Ui::AudioExpander::advOutMultiTracks[2];
	instance->advOutMultiTrack4 = Ui::AudioExpander::advOutMultiTracks[3];
	instance->advOutMultiTrack5 = Ui::AudioExpander::advOutMultiTracks[4];
	instance->advOutMultiTrack6 = Ui::AudioExpander::advOutMultiTracks[5];
	QWidget::setTabOrder(Ui::AudioExpander::advOutMultiTracks.back(), instance->advOutEncoder);

	for (uchar count = 0; count < 32; count++) {
		QPointer<QCheckBox> advOutRecTrack = new QCheckBox(instance->recTracks);
		advOutRecTrack->setObjectName("advOutRecTrack" + (count + 1));
		sizePolicy9.setHeightForWidth(advOutRecTrack->sizePolicy().hasHeightForWidth());
		advOutRecTrack->setSizePolicy(sizePolicy9);
		advOutRecTrack->setText(QString::fromUtf8("" + (count + 1)));

		instance->horizontalLayout_9->addWidget(advOutRecTrack);
		if (Ui::AudioExpander::advOutRecTracks.size() > 1)
			QWidget::setTabOrder(Ui::AudioExpander::advOutRecTracks.back(), advOutRecTrack);
		Ui::AudioExpander::advOutRecTracks.push_back(advOutRecTrack);
	}

	instance->advOutRecTrack1 = Ui::AudioExpander::advOutRecTracks[0];
	instance->advOutRecTrack2 = Ui::AudioExpander::advOutRecTracks[1];
	instance->advOutRecTrack3 = Ui::AudioExpander::advOutRecTracks[2];
	instance->advOutRecTrack4 = Ui::AudioExpander::advOutRecTracks[3];
	instance->advOutRecTrack5 = Ui::AudioExpander::advOutRecTracks[4];
	instance->advOutRecTrack6 = Ui::AudioExpander::advOutRecTracks[5];
	QWidget::setTabOrder(instance->advOutRecFormat, instance->advOutRecTrack1);
	QWidget::setTabOrder(Ui::AudioExpander::advOutRecTracks.back(), instance->advOutRecEncoder);

	for (uchar count = 0; count < 32; count++) {
		QPointer<QRadioButton> flvTrack = new QRadioButton(instance->flvTracks);
		flvTrack->setObjectName("flvTrack" + (count + 1));
		sizePolicy9.setHeightForWidth(flvTrack->sizePolicy().hasHeightForWidth());
		flvTrack->setSizePolicy(sizePolicy9);

		instance->horizontalLayout_8->addWidget(flvTrack);
		flvTrack->setText(QCoreApplication::translate("OBSBasicSettings", "" + (count + 1), nullptr));
		Ui::AudioExpander::flvTracks.push_back(flvTrack);
	}

	instance->flvTrack1 = Ui::AudioExpander::flvTracks[0];
	instance->flvTrack2 = Ui::AudioExpander::flvTracks[1];
	instance->flvTrack3 = Ui::AudioExpander::flvTracks[2];
	instance->flvTrack4 = Ui::AudioExpander::flvTracks[3];
	instance->flvTrack5 = Ui::AudioExpander::flvTracks[4];
	instance->flvTrack6 = Ui::AudioExpander::flvTracks[5];

	for (uchar count = 0; count < 32; count++) {
		QPointer<QCheckBox> advOutFFTrack = new QCheckBox(instance->widget_10);
		advOutFFTrack->setObjectName("advOutFFTrack" + (count + 1));
		advOutFFTrack->setText(QString::fromUtf8("" + (count + 1)));

		instance->horizontalLayout_26->addWidget(advOutFFTrack);
		Ui::AudioExpander::advOutFFTracks.push_back(advOutFFTrack);
	}

	instance->advOutFFTrack1 = Ui::AudioExpander::advOutFFTracks[0];
	instance->advOutFFTrack2 = Ui::AudioExpander::advOutFFTracks[1];
	instance->advOutFFTrack3 = Ui::AudioExpander::advOutFFTracks[2];
	instance->advOutFFTrack4 = Ui::AudioExpander::advOutFFTracks[3];
	instance->advOutFFTrack5 = Ui::AudioExpander::advOutFFTracks[4];
	instance->advOutFFTrack6 = Ui::AudioExpander::advOutFFTracks[5];

	QSizePolicy sizePolicy7(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
	sizePolicy7.setHorizontalStretch(0);
	sizePolicy7.setVerticalStretch(0);
	sizePolicy7.setHeightForWidth(instance->scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());

	QSizePolicy sizePolicy11(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
	sizePolicy11.setHorizontalStretch(0);
	sizePolicy11.setVerticalStretch(0);
	sizePolicy11.setHeightForWidth(instance->advOutRecPath->sizePolicy().hasHeightForWidth());
	instance->advOutRecPath->setSizePolicy(sizePolicy11);

	instance->scrollAreaWidgetContents_3->setSizePolicy(sizePolicy7);

	QPointer<QLineEdit> last;
	for (uchar count = 0; count < 32; count++) {
		QPointer<QGroupBox> current_box = new QGroupBox(instance->scrollAreaWidgetContents_7);

		current_box->setObjectName("label_nadir_edit_groupBox_" + (count + 1));
		sizePolicy7.setHeightForWidth(current_box->sizePolicy().hasHeightForWidth());
		current_box->setSizePolicy(sizePolicy7);

		QPointer<QFormLayout> formLayout = new QFormLayout(current_box);
		formLayout->setObjectName("label_nadir_edit_formLayout_" + (count + 1));
		formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
		formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
		formLayout->setContentsMargins(9, 2, 9, 9);

		QPointer<QLabel> advOutTrackBitrateLabel = new QLabel(current_box);

		std::string build_bitrate = "advOutTrack" + (count + 1);
		build_bitrate += "BitrateLabel";

		advOutTrackBitrateLabel->setObjectName(build_bitrate);
		advOutTrackBitrateLabel->setMinimumSize(QSize(170, 0));
		advOutTrackBitrateLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

		formLayout->setWidget(0, QFormLayout::LabelRole, advOutTrackBitrateLabel);

		QPointer<QComboBox> advOutTrackBitrate = new QComboBox(current_box);
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());
		advOutTrackBitrate->addItem(QString());

		std::string build_bitrate2 = "advOutTrack" + (count + 1);
		build_bitrate2 += "Bitrate";

		advOutTrackBitrate->setObjectName(build_bitrate2);
		sizePolicy7.setHeightForWidth(advOutTrackBitrate->sizePolicy().hasHeightForWidth());
		advOutTrackBitrate->setSizePolicy(sizePolicy7);

		formLayout->setWidget(0, QFormLayout::FieldRole, advOutTrackBitrate);

		QPointer<QLabel> label = new QLabel(current_box);
		label->setObjectName("label_nadir_edit_label_" + (count + 1));

		formLayout->setWidget(1, QFormLayout::LabelRole, label);

		QPointer<QLineEdit> advOutTrackName = new QLineEdit(current_box);

		std::string build_trackname = "advOutTrack" + (count + 1);
		build_trackname += "Name";

		advOutTrackName->setObjectName(build_trackname);
		sizePolicy11.setHeightForWidth(advOutTrackName->sizePolicy().hasHeightForWidth());
		advOutTrackName->setSizePolicy(sizePolicy11);

		formLayout->setWidget(1, QFormLayout::FieldRole, advOutTrackName);
		if (count == 0)
			QWidget::setTabOrder(instance->advOutSplitFileSize, advOutTrackBitrate);
		else
			QWidget::setTabOrder(last, advOutTrackBitrate);
		QWidget::setTabOrder(advOutTrackBitrate, advOutTrackName);
		last = advOutTrackName;

		advOutTrackBitrate->setCurrentIndex(8);

		label->setText(QCoreApplication::translate("OBSBasicSettings", "Name", nullptr));

#if QT_CONFIG(shortcut)
		advOutTrackBitrateLabel->setBuddy(advOutTrackBitrate);
		label->setBuddy(advOutTrackName);
#endif
		advOutTrackBitrateLabel->setText(QCoreApplication::translate(
			"OBSBasicSettings", "Basic.Settings.Output.AudioBitrate", nullptr));
		current_box->setTitle(QCoreApplication::translate(
			"OBSBasicSettings", "Basic.Settings.Output.Adv.Audio.Track" + (count + 1), nullptr));
		advOutTrackBitrateLabel->setText(QCoreApplication::translate(
			"OBSBasicSettings", "Basic.Settings.Output.AudioBitrate", nullptr));
		advOutTrackBitrate->setItemText(0,
						QCoreApplication::translate("OBSBasicSettings", "32", nullptr));
		advOutTrackBitrate->setItemText(1,
						QCoreApplication::translate("OBSBasicSettings", "48", nullptr));
		advOutTrackBitrate->setItemText(2,
						QCoreApplication::translate("OBSBasicSettings", "64", nullptr));
		advOutTrackBitrate->setItemText(3,
						QCoreApplication::translate("OBSBasicSettings", "80", nullptr));
		advOutTrackBitrate->setItemText(4,
						QCoreApplication::translate("OBSBasicSettings", "96", nullptr));
		advOutTrackBitrate->setItemText(5, QCoreApplication::translate("OBSBasicSettings", "112",
										nullptr));
		advOutTrackBitrate->setItemText(6, QCoreApplication::translate("OBSBasicSettings", "128",
										nullptr));
		advOutTrackBitrate->setItemText(7, QCoreApplication::translate("OBSBasicSettings", "160",
										nullptr));
		advOutTrackBitrate->setItemText(8, QCoreApplication::translate("OBSBasicSettings", "192",
										nullptr));
		advOutTrackBitrate->setItemText(9, QCoreApplication::translate("OBSBasicSettings", "256",
										nullptr));
		advOutTrackBitrate->setItemText(10, QCoreApplication::translate("OBSBasicSettings", "320",
										nullptr));

		instance->verticalLayout_28->addWidget(current_box);
	}
	QWidget::setTabOrder(last, instance->advRBSecMax);
}

/* clang-format off */
#define COMBO_CHANGED   &QComboBox::currentIndexChanged
#define EDIT_CHANGED    &QLineEdit::textChanged
#define CBEDIT_CHANGED  &QComboBox::editTextChanged
#define CHECK_CHANGED   &QCheckBox::toggled
#define GROUP_CHANGED   &QGroupBox::toggled
#define SCROLL_CHANGED  &QSpinBox::valueChanged
#define DSCROLL_CHANGED &QDoubleSpinBox::valueChanged
#define TEXT_CHANGED    &QPlainTextEdit::textChanged

#define GENERAL_CHANGED &Ui::OBSBasicSettings::GeneralChanged
#define STREAM1_CHANGED &Ui::OBSBasicSettings::Stream1Changed
#define OUTPUTS_CHANGED &Ui::OBSBasicSettings::OutputsChanged
#define AUDIO_RESTART   &Ui::OBSBasicSettings::AudioChangedRestart
#define AUDIO_CHANGED   &Ui::OBSBasicSettings::AudioChanged
#define VIDEO_RES       &Ui::OBSBasicSettings::VideoChangedResolution
#define VIDEO_CHANGED   &Ui::OBSBasicSettings::VideoChanged
#define A11Y_CHANGED    &Ui::OBSBasicSettings::A11yChanged
#define APPEAR_CHANGED  &Ui::OBSBasicSettings::AppearanceChanged
#define ADV_CHANGED     &Ui::OBSBasicSettings::AdvancedChanged
#define ADV_RESTART     &Ui::OBSBasicSettings::AdvancedChangedRestart
/* clang-format on */

template<class OBSBasicSettings, typename Widget, typename WidgetParent, typename... SignalArgs, typename... SlotArgs>
inline void Ui::AudioExpander::redirect(Ui::OBSBasicSettings *instance, Widget *widget,
				    void (WidgetParent::*signal)(SignalArgs...),
				    void (OBSBasicSettings::*slot)(SlotArgs...))
{
	instance->ReHookWidget(widget, signal, slot);
}

void Ui::AudioExpander::HookWidgets(Ui::OBSBasicSettings *instance)
{
	foreach(QPointer<QCheckBox> simpleOutRecTrack, simpleOutRecTracks)
	{
		Ui::AudioExpander::redirect<OBSBasicSettings,>(instance, simpleOutRecTrack, CHECK_CHANGED,
							      OUTPUTS_CHANGED);
		redirect(instance, simpleOutRecTrack, CHECK_CHANGED, OUTPUTS_CHANGED);
	}
	foreach(QPointer<QRadioButton> advOutTrack, advOutTracks)
	{
		Ui::AudioExpander::redirect(*instance, *advOutTrack, CHECK_CHANGED, OUTPUTS_CHANGED);
	}
	foreach(QPointer<QCheckBox> advOutMultiTrack, advOutMultiTracks)
	{
		QObject::connect(advOutMultiTrack, &QCheckBox::toggled, instance,
				 &Ui::OBSBasicSettings::OutputsChanged);
		advOutMultiTrack->setProperty("changed", QVariant(false));
	}
	foreach(QPointer<QCheckBox> advOutRecTrack, advOutRecTracks)
	{
		QObject::connect(*advOutRecTrack, CHECK_CHANGED, instance, OUTPUTS_CHANGED);
		advOutRecTrack->setProperty("changed", QVariant(false));
	}
}
