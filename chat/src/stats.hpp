#include <QList>
#include <QString>

class Stats {
public:
	QString toString();
	qint64 average();
	qint64 stddev();
	void append(qint64);
	void clear();
	void shift(qint64 offset);
	int count();
private:
	QList<qint64> list;
};
