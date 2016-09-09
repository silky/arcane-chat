#pragma once

#define QT_NO_SIGNALS_SLOTS_KEYWORDS

#include <QObject>

#include <Qt5GStreamer/QGst/Pipeline>
#include <Qt5GStreamer/QGst/Message>
#include <Qt5GStreamer/QGst/Utils/ApplicationSource>
#include "toxsink.hpp"

namespace chat {
    class Core;
    class Friend;
}

class AudioCall : public QObject
{
    Q_OBJECT
public:
    explicit AudioCall(chat::Core *core, chat::Friend *fr);
    ~AudioCall();
    void start();
    void stop();
    void packet(QByteArray data);

    ssize_t write_fn(QByteArray data);
Q_SIGNALS:

public Q_SLOTS:
    void onBusMessage(const QGst::MessagePtr & message);
private:
    //bool on_bus_message(const Glib::RefPtr<Gst::Bus>&,
    //                    const Glib::RefPtr<Gst::Message>& message);

    chat::Core *core;
    chat::Friend *fr;
    QGst::PipelinePtr outbound;
    QGst::PipelinePtr inbound;
    chat::ToxSink m_sink;
    QGst::Utils::ApplicationSource m_src;
};