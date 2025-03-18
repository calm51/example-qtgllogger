#include <QCoreApplication>

#include <qtgllogger/qtgllogger.h>


QGL_LOGGER_OBJECT_EXTERN; // 文件内

namespace MyNS1 {

QGL_LOGGER_OBJECT_EXTERN; // 命名空间内

class MyCls1 {
  public:
    QGL_LOGGER_OBJECT_STATIC; // 类内

    MyCls1() { init(); }
    void init() { QGL_INFO("init1"); }
    ~MyCls1() { qgl.debug("~析构", this); }
};

} // namespace MyNS1

class MyCls2 {
  public:
    QGL_LOGGER_OBJECT_STATIC;

    MyCls2() { init(); }
    void init() { QGL_INFO("init2"); }
    ~MyCls2() { qgl.debug("~析构", this); }
};


QGL_LOGGER_OBJECT_DEFINE(MyNS1); // 实例化
QGL_LOGGER_OBJECT_DEFINE(MyNS1::MyCls1);
QGL_LOGGER_OBJECT_DEFINE(MyCls2);


int main(int argc, char *argv[]) {
    QGL_LOGGER_OBJECT_DEFINE_FOR_FILE(1); // 实例化

    QGL_LINE_LINE_BEGIN(QGL::Level::Trace);

    QGL_TRACE("trace"); // 记录日志

    qgl.trace("t1");
    qgl.trace_ext({}, 3, 4);

    QGL_INFO(0);

    QGL::QGL_INFO(1);

    MyNS1::QGL_INFO(2);

    MyNS1::MyCls1 object1;
    object1.qgl.warning(3);

    MyCls2 object2;
    object2.qgl.error(4);

    MyCls2 object3;
    object3.qgl.error(5);

    QGL_INFO(QGL::e2s(QGL::Level::Debug), QGL::e2s_lastpart(QGL::Level::Debug)); // 枚举转qstring
    QGL_INFO(QGL::Level::Debug);                                                 // qdebug打印枚举

    QGL_INFO(qgl); // qdebug打印对象
    QGL_INFO(MyNS1::qgl);
    QGL_INFO(MyNS1::MyCls1::qgl, object1.qgl);
    QGL_INFO(MyCls2::qgl, object3.qgl);

    QGL_LINE_LINE_END(QGL::Level::Trace);

    QGL_INFO(QGL::loggers);

    return 0;
}
