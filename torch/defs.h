#ifndef DEFS_H
#define DEFS_H
// Коды результата
#define READY                0x00                                        // Готов
#define STARTED              0x01                                        // Запущен
#define CONNECTION_ERROR     0x02                                        // Ошибка соединения
#define CONNECTION_DISCARDED 0x03                                        // Соединение сброшено
#define THREAD_DELETED       0x04                                        // Поток завершен
// Коды команд
#define ONDELETE             0x20                                        // Удалить поток
#define ONSTART              0x21                                        // Старт соединения
#define ONSTOP               0x22                                        // Остановить работу

#endif // DEFS_H
