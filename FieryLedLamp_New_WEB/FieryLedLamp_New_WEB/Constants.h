// Текущая версия : FieryLedLamp v3.8_new_web 122 эффекта
// ВНИМАНИЕ!!! Большая часть настроек перенесена в файл data/config и может изменяться в процессе эксплуатации лампы.
// Внимательно читайте файл ПРОЧТИ МЕНЯ!!!.txt и ПРОЧТИ МЕНЯ.doc (тут с картинками)

#pragma once

#define FLL_VERSION           (" Ver.3.8.122")

//#include <ESP8266WebServer.h>

// ============= НАСТРОЙКИ =============
//#define USE_SECRET_COMMANDS                               // удалите эту строку, если вам не нужна возможность смены режимов работы ESP_MODE и обнуления настроек из приложения
                                                            // список секретных команд тут: https://community.alexgyver.ru/threads/nastrojka-programmy-blynk-dlja-fiery-led-lamp.7787/
//#define USE_BLYNK  ("сюда_вставить_токен_из_приложения")  // раскомментируйте эту строку, если вы используете приложение Blynk (для iOS и Android) https://community.alexgyver.ru/threads/nastrojka-programmy-blynk-dlja-fiery-led-lamp.7787/
                                                            // токен берут в приложении в "настройки -> DEVICES -> MY DEVICES -> AUTH TOKEN"
uint8_t DONT_TURN_ON_AFTER_SHUTDOWN;                        // Не удаляйте  и не комментируйте эту строку
uint32_t AUTOMATIC_OFF_TIME = (0UL);                        // Не удаляйте и не комментируйте эту строку
#define USE_DEFAULT_SETTINGS_RESET                          // закомментируйте или удалите эту строку, если не нужно, чтобы при загрузке списка эффектов из лампы в приложение настройки эффектов сбрасывались на значения по умолчанию

// --- КНОПКА --------------------------
#define ESP_USE_BUTTON                                      // Не удаляйте и не комментируйте эту строку (если не подключает кнопку, оключите на web странице)
#define BUTTON_IS_SENSORY     (1)                           // если у вас не сенсорная, а обычная кнопка, поменяйте в этой строчке 1 на нолик 
#define BUTTON_LOCK_ON_START                                // с этой строкой, если в момент включения лампы в розетку успеть нажать кнопку, или если вы забудете кнопку подключить, лампа отключит реакцию на нажатие кнопки до следующего раза
#define BUTTON_CAN_SET_SLEEP_TIMER                          // с этой строчкой, если на лампе набить кнопкой 4х кратно (один раз), лампа мигнёт дважды синим и если она выключена , то включится.
                                                            // Таймер выключения лампы будет установлен на BUTTON_SET_SLEEP_TIMER1 минут. Если на лампе набить кнопкой 3х кратно + удержание 4го нажатия, лампа мигнёт синим трижды и если она выключена , то включится.
                                                            // Таймер выключения лампы будет установлен на BUTTON_SET_SLEEP_TIMER2 минут. Чтобы убрать эту функцию, удалите или закомментируйте эту строчку
#ifdef BUTTON_CAN_SET_SLEEP_TIMER
  #define BUTTON_SET_SLEEP_TIMER1   (5UL)                   
  #define BUTTON_SET_SLEEP_TIMER2   (10UL)
#endif

#define ESP_CONF_TIMEOUT      (60U)                         // время в секундах, которое лампа будет ждать от вас введения пароля для ОТА обновления (пароль совпадает с паролем точки доступа)

#define USE_MULTIPLE_LAMPS_CONTROL                          // Включать код для управления несколькими лампами

//#define MP3_DEBUG                                         // если строка не закомментирована, выводятся отладочные сообщения mp3 player
//#define HEAP_SIZE_PRINT                                   // если строка не закомментирована, будет выводиться размер "купи" (свободного ОЗУ)
//#define GENERAL_DEBUG                                     // если строка не закомментирована, будут выводиться общие отладочные сообщения

#define LED_PIN               (0U)                          // пин ленты                (D3) на (D4) - встроенный светодиод платы , поэтому лучше паять на D3 = #define LED_PIN (0U)
#define BTN_PIN               (4U)                          // пин кнопки               (D2)
#define MOSFET_PIN            (5U)                          // пин MOSFET транзистора   (D1) - может быть использован для управления питанием матрицы/ленты (если раскомментировать строку)
#define MOSFET_LEVEL          (HIGH)                        // логический уровень, в который будет установлен пин MOSFET_PIN, когда матрица включена - HIGH или LOW (если раскомментировать)
//#define ALARM_PIN             (15U)                       // пин состояния будильника (D8) - может быть использован для управления каким-либо внешним устройством на время работы будильника (если раскомментировать)
//#define ALARM_LEVEL           (HIGH)                      // логический уровень, в который будет установлен пин ALARM_PIN, когда "рассвет"/будильник включен (если раскомментировать)

#define USE_LittleFS                                        // Закомментируйте эту строку, если вместо файловой системы LittlFS  хотите использовать файловую систему SPIFFS

#ifdef ESP_USE_BUTTON
#define DISPLAY_IP_AT_START                                 // Раскоментируйте эту строчку, если хотите, чтобы при включении пмтания и подключению к WiFi, лампа один раз выводила свой IP адрес (для ламп с кнопкой)
#else
   #define DISPLAY_IP_AT_START                              // Закоментируйте эту строчку, если не хотите, чтобы при включении пмтания и подключению к WiFi, лампа один раз выводила свой IP адрес (для ламп без кнопки)
#endif  //ESP_USE_BUTTON

#define TM1637_USE                                          // Закоментируйте, если не используется дисплей TM1637
#ifdef TM1637_USE
#define DIO                   (16U)                         // D0 TM1637 display DIO pin
#define CLK                   (14U)                         // D5 TM1637 display CLK pin
#endif  //TM1637_USE

#define MP3_TX_PIN            (12U)                         // В СЛУЧАЕ ОТСУТСТВИЯ ПЛЕЕРА ЗАКОМЕНТМРОВАТЬ СТРОКУ!!! Определяет вывод TX (D6)(RX на плеере)  
#define MP3_RX_PIN            (13U)                         // Определяет вывод RX (D7)(TX на плеере) программного последовательного порта
#ifdef MP3_TX_PIN
  //#define CHECK_MP3_CONNECTION                            // Закоментируйте эту строку если нужно, чтобы лампа не проверяла наличие связи с МР3 плеером
  //#define DF_PLAYER_IS_ORIGINAL                           // Если используеися плеер с чипом, отличным от AS20HGN402 ,закоментируйте эту строку
  #ifndef  DF_PLAYER_IS_ORIGINAL
    //#define DF_PLAYER_GD3200x                             // Если у вас такой чип в плеере и эта строка не закомментирована, то для озвучивания времени используются разные голоса.
  #endif  //DF_PLAYER_IS_ORIGINAL
#endif  //MP3_TX_PIN

#define IR_RECEIVER_USE                                     // Если не используется ИК ДУ - Закомментировать эту строку
#ifdef IR_RECEIVER_USE
  #define IR_RECEIVER_PIN  2                                // Пин ИК сенсора D4
#endif  //IR_RECEIVER_USE

// --- ESP (WiFi клиент) ---------------
                                                            // SSID и пароль Вашей WiFi-сети задаются на web странице лампы в режиме WiFi точки доступа по IP 192.168.4.1            
                                                            // Там же задаётся время в секундах (таймаут), которое ESP будет пытаться подключиться к WiFi сети, после его истечения автоматически развернёт WiFi точку доступа
#define	INTERNET_CHECK_PERIOD	(60UL)                        // Период повторной проверки наличия интернета в секундах


// --- AP (WiFi точка доступа) ---
String AP_NAME ="";                                         // Переменная для имени точки доступа. Задаётся на web странице
String AP_PASS = "";                                        // Переменная для пароля точки доступа. Задаётся на web странице
String LAMP_NAME = "";                                      // Переменная для имени Лампы. Задаётся на web странице
const uint8_t AP_STATIC_IP[] = {192, 168, 4, 1};            // статический IP точки доступа (лучше не менять!)

// --- ВРЕМЯ ---------------------------
#define GET_TIME_FROM_PHONE (5U)                            // с этой строчкой время в лампе само синхронизируется с приложением, когда лампа не имеет или потеряла доступ в интернет на сервер точного времени .
                                                            // для этого нужно использовать приложение FireLamp версии 3.0 или выше, либо другое приложение, которое отправляет время телефона в лампу. 
                                                            // цифра 5U означает, что синхранизация не чаще, чем раз в 5 минут. переход на зимнее время произойдёт только если изменение пришло со смартфона!
//#define USE_MANUAL_TIME_SETTING                           // с этой строчкой у вас будет возможность устанавливать время на лампе из приложения вручную (например, когда лампа не имеет доступа в интернет)
                                                            // для этого в приложении в поле для текста бегущей строки нужно вписать "time=ЧЧ:ММ Д" в 24-часовом формате
                                                            // например, time=07:25 4  - означает, что время будет установлено на 7 часов 25 минут, четверг
                                                            // время установится в момент нажатия кнопки "НАЗАД" или "ОТПРАВИТЬ", секунды будут по нулям. лампа мигнёт голубым цветом при удачной установке
#define PHONE_N_MANUAL_TIME_PRIORITY                        // с этой строчкой, если время получено через приложение, то попытки синхронизации с NTP-сервером прекращаются (пригодится тем, у кого возникают проблемы с NTP-сервером)
#define WARNING_IF_NO_TIME      (7U)                        // с этой строчкой лампа будет подмигивать в нижнем ряде светодиодов, когда она не знает, сколько сейчас времени.
                                                            // 7 - это яркость мигающих точек (максимум - 255U), когда лампа выключена
#define WARNING_IF_NO_TIME_ON_EFFECTS_TOO                   // а если эту строку раскомментировать, то подмигивание будет даже во время работы эффектов. яркость точек будет, как у работающего эффекта


#define USE_NTP                                             // закомментировать или удалить эту строку, если нужно, чтобы лампа не обращалась в интернет на сервер времени (NTP-сервер).
                                                            // Стоит её убрать только в том случае, если в вашей домашней сети нет круглосуточного доступа в интернет.
                                                            // Лампу можно отправить в другой часовой пояс, так как часовой пояс, выставляется на web странице. 
                                                            // Там же чекбоксом выбирается необходимость перехода на летнее время.
char NTP_ADDRESS [32];                                      // Не удаляйте и не комментируйте эту строку
															
#define NTP_INTERVAL          (59 * 60UL * 1000UL)          // интервал синхронизации времени (59 минут)

// --- ВЫВОД ВРЕМЕНИ БЕГУЩЕЙ СТРОКОЙ ---
unsigned int NIGHT_HOURS_START;                             // Не удаляйте и не комментируйте эту строку
unsigned int NIGHT_HOURS_STOP;                              // Не удаляйте и не комментируйте эту строку
unsigned int DAY_HOURS_BRIGHTNESS;                          // Не удаляйте и не комментируйте эту строку
unsigned int NIGHT_HOURS_BRIGHTNESS;                        // Не удаляйте и не комментируйте эту строку                        
                                                            // константы DAY_HOURS_BRIGHTNESS и NIGHT_HOURS_BRIGHTNESS используются только, когда матрица выключена, иначе будет использована яркость текущего эффекта
// --- Яркость вспышки ПРЕДУПРЕЖДЕНИЕ showWarning ---
#define WARNING_BRI_DAY    (10U)                            // Яркость вспышки предупреждение днем
#define WARNING_BRI_NIGHT    (5U)                           // Яркость вспышки предупреждения ночью

// --- МАТРИЦА -------------------------
// Настраивается на web странице
#define CURRENT_LIMIT         (4000U)                       // лимит по току в миллиамперах, автоматически управляет яркостью (пожалей свой блок питания!) 0 - выключить лимит

#define WIDTH                 (16)                          // ширина матрицы
#define HEIGHT                (16)                          // высота матрицы

#define COLOR_ORDER           (GRB)                         // порядок цветов на ленте. Если цвет отображается некорректно - меняйте. Начать можно с RGB

uint8_t ORIENTATION;
uint8_t MATRIX_TYPE = 0;                                    // тип матрицы: 0 - зигзаг, 1 - параллельная
#define CONNECTION_ANGLE      (0U)                          // угол подключения: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний
#define STRIP_DIRECTION       (0U)                          // направление ленты из угла: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз
                                                            // при неправильной настройке матрицы вы получите предупреждение "Wrong matrix parameters! Set to default"
                                                            // шпаргалка по настройке матрицы здесь: https://alexgyver.ru/wp-content/uploads/2018/11/scheme3.jpg
                                                            // (но в ней, кажется, перепутаны местами квадратики в 4м столбце, а может, и ещё какие-то)

// --- ЭФФЕКТЫ -------------------------
#define RUNNING_TEXT_DEFAULT  ("Привет!")                   // текст, который будет выводиться в эффекте Бегущая строка по умолчанию. его можно менять на web странице

// == названия и номера эффектов ниже в списке используются на вкладке effectTricker ==
// == если меняете, меняйте и там, и ещё здесь ниже в РЕЕСТРЕ ДОСТУПНЫХ ЭФФЕКТОВ ==
     
#define EFF_WHITE_COLOR         (  0U)    // Бeлый cвeт
#define EFF_WATERCOLOR          (  1U)    // Акварель
#define EFF_FLOWERRUTA          (  2U)    // Аленький цветочек
#define EFF_EFF_POOL            (  3U)    // Бассейн
#define EFF_BAMBOO              (  4U)    // Бамбук
#define EFF_MADNESS             (  5U)    // Безумие
#define EFF_BALLROUTINE         (  6U)    // Блуждающий кубик
#define EFF_WATERFALL           (  7U)    // Водопад
#define EFF_WATERFALL_4IN1      (  8U)    // Водопад 4в1
#define EFF_WAVES               (  9U)    // Волны
#define EFF_MAGICLANTERN        ( 10U)    // Волшебный Фонарик
#define EFF_WINE                ( 11U)    // Вино
#define EFF_WHIRL               ( 12U)    // Вихри пламени
#define EFF_WHIRL_MULTI         ( 13U)    // Вихри разноцветные
#define EFF_STARFALL            ( 14U)    // Вьюга
#define EFF_STORMY_RAIN         ( 15U)    // Гроза в банке
#define EFF_DNA                 ( 16U)    // ДНК
#define EFF_SMOKE               ( 17U)    // Дым
#define EFF_SMOKE_COLOR         ( 18U)    // Дым разноцветный
#define EFF_SMOKEBALLS          ( 19U)    // Дымовые шашки
#define EFF_LIQUIDLAMP          ( 20U)    // Жидкая лампа
#define EFF_LIQUIDLAMP_AUTO     ( 21U)    // Жидкая лампа авто
#define EFF_SWIRL               ( 22U)    // Завиток
#define EFF_STARS               ( 23U)    // Звезды
#define EFF_ZEBRA               ( 24U)    // Зебра
#define EFF_TIXYLAND            ( 25U)    // Земля Тикси
#define EFF_SNAKES              ( 26U)    // Змейки
#define EFF_FOUNTAIN            ( 27U)    // Источник
#define EFF_DROP_IN_WATER       ( 28U)    // Капли на воде
#define EFF_DROPS               ( 29U)    // Капли на стекле
#define EFF_LLAND               ( 30U)    // Кипение
#define EFF_RINGS               ( 31U)    // Кодовый замок
#define EFF_COMET               ( 32U)    // Комета
#define EFF_COMET_COLOR         ( 33U)    // Комета одноцветная
#define EFF_COMET_TWO           ( 34U)    // Комета двойная
#define EFF_COMET_THREE         ( 35U)    // Комета тройная
#define EFF_CONTACTS            ( 36U)    // Контакты
#define EFF_SPARKLES            ( 37U)    // Конфетти
#define EFF_CUBE2D              ( 38U)    // Кубик Рубика
#define EFF_LAVA                ( 39U)    // Лава
#define EFF_LAVALAMP            ( 40U)    // Лавовая лампа
#define EFF_BUTTERFLYS_LAMP     ( 41U)    // Лампа с мотыльками
#define EFF_FOREST              ( 42U)    // Лес
#define EFF_LUMENJER            ( 43U)    // Люмeньep
#define EFF_MAGMA               ( 44U)    // Магма
#define EFF_PAINTS              ( 45U)    // Масляные краски
#define EFF_MATRIX              ( 46U)    // Матрица
#define EFF_TWINKLES            ( 47U)    // Мерцание
#define EFF_METABALLS           ( 48U)    // Метоболз
#define EFF_WEB_TOOLS           ( 49U)    // Мечта дизайнера
#define EFF_MOSAIC              ( 50U)    // Мозайка
#define EFF_BUTTERFLYS          ( 51U)    // Moтыльки
#define EFF_BBALLS              ( 52U)    // Мячики
#define EFF_BALLS_BOUNCE        ( 53U)    // Мячики без границ
#define EFF_CHRISTMAS_TREE      ( 54U)    // Новогодняя Елка
#define EFF_FIRE                ( 55U)    // Огонь
#define EFF_FIRE_2012           ( 56U)    // Огонь 2012
#define EFF_FIRE_2018           ( 57U)    // Огонь 2018
#define EFF_FIRE_2020           ( 58U)    // Огонь 2020
#define EFF_FIRE_2021           ( 59U)    // Огонь 2021
#define EFF_FIREFLY_TOP         ( 60U)    // Огoнь верховой
#define EFF_FIREFLY             ( 61U)    // Огoнь парящий
#define EFF_FIRESPARKS          ( 62U)    // Огонь с искрами
#define EFF_COLOR_RAIN          ( 63U)    // Осадки
#define EFF_OSCILLATING         ( 64U)    // Осциллятор
#define EFF_CLOUDS              ( 65U)    // Облака
#define EFF_OCEAN               ( 66U)    // Океан
#define EFF_OCTOPUS             ( 67U)    // Осьминог
#define EFF_RAINBOW_STRIPE      ( 68U)    // Павлин
#define EFF_HOURGLASS           ( 69U)    // Песочные часы
#define EFF_PAINTBALL           ( 70U)    // Пейнтбол
#define EFF_PICASSO             ( 71U)    // Пикассо
#define EFF_PLASMA              ( 72U)    // Плазма
#define EFF_SPIDER              ( 73U)    // Плазменная лампа
#define EFF_PLASMA_WAVES        ( 74U)    // Плазменные волны
#define EFF_FLAME               ( 75U)    // Пламя
#define EFF_PLANETEARTH         ( 76U)    // Планета Земля
#define EFF_BY_EFFECT           ( 77U)    // Побочный эффект
#define EFF_POPCORN             ( 78U)    // Попкорн
#define EFF_PRISMATA            ( 79U)    // Призмата
#define EFF_ATTRACT             ( 80U)    // Притяжение
#define EFF_LEAPERS             ( 81U)    // Пpыгyны
#define EFF_PULSE               ( 82U)    // Пульс
#define EFF_PULSE_WHITE         ( 83U)    // Пульс белый
#define EFF_PULSE_RAINBOW       ( 84U)    // Пульс радужный
#define EFF_RADIAL_WAWE         ( 85U)    // Радиальная волна
#define EFF_RAINBOW_VER         ( 86U)    // Радуга
#define EFF_RAINBOW             ( 87U)    // Радуга 3D
#define EFF_SNAKE               ( 88U)    // Радужный змей
#define EFF_DANDELIONS          ( 89U)    // Разноцветные одуванчики
#define EFF_RAIN                ( 90U)    // Разноцветный дождь
#define EFF_RIVERS              ( 91U)    // Реки Ботсваны
#define EFF_LIGHTERS            ( 92U)    // Светлячки
#define EFF_LIGHTER_TRACES      ( 93U)    // Светлячки со шлейфом
#define EFF_FEATHER_CANDLE      ( 94U)    // Свеча
#define EFF_AURORA              ( 95U)    // Северное сияние
#define EFF_SERPENTINE          ( 96U)    // Серпантин
#define EFF_SINUSOID3           ( 97U)    // Синусоид
#define EFF_COLORS              ( 98U)    // Смена цвета
#define EFF_SNOW                ( 99U)    // Снегопад
#define EFF_SPECTRUM            (100U)    // Спектрум
#define EFF_SPIRO               (101U)    // Спирали
#define EFF_FLOCK               (102U)    // Стая
#define EFF_FLOCK_N_PR          (103U)    // Стая и хищник
#define EFF_ARROWS              (104U)    // Стрелки
#define EFF_STROBE              (105U)    // Строб.Хаос.Дифузия
#define EFF_SHADOWS             (106U)    // Тени
#define EFF_PACIFIC             (107U)    // Тихий океан
#define EFF_TORNADO             (108U)    // Торнадо
#define EFF_SIMPLE_RAIN         (109U)    // Tyчкa в банке
#define EFF_FIREWORK            (110U)    // Фейерверк
#define EFF_FIREWORK_2          (111U)    // Фейерверк 2
#define EFF_FAIRY               (112U)    // Фея
#define EFF_COLOR               (113U)    // Цвет
#define EFF_EFF_COLORED_PYTHON  (114U)    // Цветной Питон
#define EFF_EFF_SAND            (115U)    // Цветные драже
#define EFF_COLOR_FRIZZLES      (116U)    // Цветные кудри
#define EFF_EFF_LOTUS           (117U)    // Цветок лотоса
#define EFF_TURBULENCE          (118U)    // Цифровая турбулентность
#define EFF_SPHERES             (119U)    // Шapы
#define EFF_NEXUS               (120U)    // Nexus
#define EFF_CLOCK               (121U)    // Часы

#define MODE_AMOUNT         (122U)    // количество режимов

// ============= МАССИВ НАСТРОЕК ЭФФЕКТОВ ПО УМОЛЧАНИЮ ===================
// формат записи:
//{ Яркость, Скорость, Масштаб}

static const uint8_t defaultSettings[][3] PROGMEM = {
  {  10,   1,  50}, // Бeлый cвeт
  {  25, 200,  65}, // Акварель
  {  20, 215,  60}, // Аленький цветочек
  {  25, 185,  63}, // Бассейн
  {  20, 215,  90}, // Бамбук
  {  35,  20,  60}, // Безумие
  {  20, 150,  50}, // Блуждающий кубик
  {  30, 212,  54}, // Водопад
  {  20, 195,  22}, // Водопад 4в1
  {  40, 233,  80}, // Волны
  {  45, 175,  60}, // Волшебный Фонарик
  {  80, 205,  40}, // Вино
  {  25, 210,   1}, // Вихри пламени
  {  20, 210,  86}, // Вихри разноцветные
  {  55, 191,  54}, // Вьюга
  {  40, 210,   8}, // Гроза в банке
  {  30,  80,  95}, // ДНК
  {  25, 195, 100}, // Дым
  {  25, 190,  30}, // Дым разноцветный
  {  30, 170,  25}, // Дымовые шашки
  {  20, 110,   1}, // Жидкая лампа
  {  20, 124,  39}, // Жидкая лампа авто
  {  30, 195,  70}, // Завиток
  {  25, 215,  99}, // Звезды
  {  15,   8,  21}, // Зебра
  {  20, 212,  76}, // Земля Тикси
  {  20,  40,  15}, // Змейки
  {  25, 233,  30}, // Источник
  {  20, 200,  55}, // Капли на воде
  {  20,  40,  59}, // Капли на стекле
  {  15, 240,  18}, // Кипение
  {  30, 205,  91}, // Кодовый замок
  {  20, 205,  28}, // Комета
  {  20, 212,  69}, // Комета одноцветная
  {  25, 186,  19}, // Комета двойная
  {  25, 186,   9}, // Комета тройная
  {  25, 200,  60}, // Контакты
  {  30, 142,  63}, // Конфетти
  {  45, 222,  92}, // Кубик Рубика
  {  15,   9,  24}, // Лава
  {  15, 240,   1}, // Лавовая лампа
  {  30,  61,  20}, // Лампа с мотыльками
  {  15,  15,  95}, // Лес
  {  20, 200,  40}, // Люмeньep
  {  16, 205,  20}, // Магма
  {  15, 195,  50}, // Масляные краски
  {  25, 186,  23}, // Матрица
  {  25, 235,   4}, // Мерцание
  {  15,  72,   3}, // Метоболз
  {  28,  70,  20}, // Мечта дизайнера
  {  15, 205,  50}, // Мозайка
  {  20,  61,  20}, // Moтыльки
  {  15, 255,  26}, // Мячики
  {  25, 255,  85}, // Мячики без границ
  {  30, 165,  30}, // Новогодняя Елка
  {  25, 210,   1}, // Огонь
  {  15, 220,  63}, // Огонь 2012
  {  30, 220,  15}, // Огонь 2018
  {  20, 225,  11}, // Огонь 2020
  {  25, 150,  22}, // Огонь 2021
  {  26, 190,  15}, // Огoнь верховой
  {  30, 200,  15}, // Огoнь парящий
  {  30,  80,  64}, // Огонь с искрами
  {  20, 205, 149}, // Осадки
  {  15, 208, 100}, // Осциллятор
  {  20,  15,  34}, // Облака
  {  20,   8,  12}, // Океан
  {  15, 200,  51}, // Осьминог
  {  20,   5,  12}, // Павлин
  {  20, 150,   1}, // Песочные часы
  {  25, 195,   1}, // Пейнтбол
  {  15, 220,  40}, // Пикассо
  {  10,  20,  35}, // Плазма
  {  10,  30,  82}, // Плазменная лампа
  {  15,  15,  50}, // Плазменные волны
  {  30,  45,   3}, // Пламя
  {  25, 128,  75}, // Планета Земля
  {  40, 165,  30}, // Побочный эффект
  {  10,  70,  16}, // Попкорн
  {  15, 100,  88}, // Призмата
  {  20, 205,  65}, // Притяжение
  {  25, 203,   5}, // Пpыгyны
  {  20, 185,   6}, // Пульс
  {  20, 179,  11}, // Пульс белый
  {  20, 185,  31}, // Пульс радужный
  {  15, 220,  50}, // Радиальная волна
  {  10, 215,  50}, // Радуга
  {  10,  13,  60}, // Радуга 3D
  {  15, 205, 100}, // Радужный змей
  {  20,  50,  90}, // Разноцветные одуванчики
  {  15, 205,   1}, // Разноцветный дождь
  {  12, 175,  50}, // Реки Ботсваны
  {  15, 180,  23}, // Светлячки
  {  15, 185,  93}, // Светлячки со шлейфом
  {  20, 220,   8}, // Свеча
  {  15, 160,  64}, // Северное сияние
  {  15,  75,  50}, // Серпантин
  {  20, 127,  75}, // Синусоид
  {  25, 240,   1}, // Смена цвета
  {  10, 205,  90}, // Снегопад
  {  25, 175, 100}, // Спектрум
  {  15,  45,   3}, // Спирали
  {  15, 136,   4}, // Стая
  {  15, 128,  80}, // Стая и хищник
  {  75, 165,  40}, // Стрелки
  {  25,   1,  45}, // Строб.Хаос.Дифузия
  {  50, 160,   1}, // Тени
  {  20, 127, 100}, // Тихий океан
  {  15, 127,  50}, // Торнадо
  {  50, 210,   2}, // Tyчкa в банке
  {  25, 180,  70}, // Фейерверк
  {  15, 240,  75}, // Фейерверк 2
  {  20, 212,  85}, // Фея
  {  20, 240,  65}, // Цвет
  {  20, 127,  92}, // Цветной Питон
  {  15, 195,  80}, // Цветные драже
  {  25, 128,  60}, // Цветные кудри
  {  15, 150,  45}, // Цветок лотоса
  {  15, 215,  35}, // Цифровая турбулентность
  {  20,  50,   5}, // Шapы
  {  25,  85,  20}, // Nexus
  {  30, 214,  80}  // Часы
}; // ^-- проверьте, чтобы у предыдущей строки не было запятой после скобки


// ------------ ОШИБАТЬСЯ НЕЛЬЗЯ!!!   ------------------------------------------------

// ============= КОНЕЦ МАССИВА =====

// === ОСТАЛЬНОЕ ДЛЯ РАЗРАБОТЧИКОВ =====
//#define USE_OLD_IOS_APP                                   // раскомментируйте эту строку, если вы используете приложение для iOS "Arduino Lamp" (удалено из Апстора, исходники на форуме)

// --- МАТРИЦА -------------------------
// если у вас не обычная матрица, а сборка из ленты или гирлянда, и возникают непонятной природы артефакты в рисунке эффекта, попробуйте менять следующие три строчки
//#define FASTLED_ALLOW_INTERRUPTS      (1)                 // default: 1; // Используйте это, чтобы заставить FastLED разрешить прерывания в безтактовых наборах микросхем (или заставить его запретить), переопределив значение по умолчанию на платформах, которые это поддерживают. Установите значение 1, чтобы разрешить прерывания, или 0, чтобы их запретить.
#define FASTLED_INTERRUPT_RETRY_COUNT   (0)                 // default: 2; // Используйте это, чтобы определить, сколько раз FastLED попытается повторно передать кадр, если он слишком долго прерывается.
#define FASTLED_ESP8266_RAW_PIN_ORDER                       // FASTLED_ESP8266_RAW_PIN_ORDER, FASTLED_ESP8266_D1_PIN_ORDER or FASTLED_ESP8266_NODEMCU_PIN_ORDER


#define NUM_LEDS              (uint16_t)(WIDTH * HEIGHT)
#define SEGMENTS              (1U)                          // диодов в одном "пикселе" (для создания матрицы из кусков ленты). вряд ли эффекты будут корректно работать, если изменить этот параметр

#define DYNAMIC                (0U)   // динамическая задержка для кадров ( будет использоваться бегунок Скорость )
#define SOFT_DELAY             (1U)   // задержка для смены кадров FPSdelay задается програмно прямо в теле эффекта
#define LOW_DELAY             (15U)   // низкая фиксированная задержка для смены кадров
#define HIGH_DELAY            (50U)   // высокая фиксированная задержка для смены кадров
#define DYNAMIC_DELAY_TICK    if (millis() - effTimer >= (256U - modes[currentMode].Speed))
#define HIGH_DELAY_TICK       if (millis() - effTimer >= 50)
#define LOW_DELAY_TICK        if (millis() - effTimer >= 15)
#define MICRO_DELAY_TICK      if (millis() - effTimer >= 2)
#define SOFT_DELAY_TICK       if (millis() - effTimer >= FPSdelay)

#define BRIGHTNESS            (40U)                         // стандартная маскимальная яркость (0-255). используется только в момент включения питания лампы

#if defined (ESP_USE_BUTTON)
#define BUTTON_STEP_TIMEOUT   (100U)                        // каждые BUTTON_STEP_TIMEOUT мс будет генерироваться событие удержания кнопки (для регулировки яркости)
#define BUTTON_CLICK_TIMEOUT  (500U)                        // максимальное время между нажатиями кнопки в мс, до достижения которого считается серия последовательных нажатий
#if (BUTTON_IS_SENSORY == 1)
  #define BUTTON_SET_DEBOUNCE   (10U)                       // Время антидребезга mS для сенсорной кнопки
#else
  #define BUTTON_SET_DEBOUNCE   (60U)                       // Время антидребезга mS для механической кнопки
#endif
#endif
#define ESP_HTTP_PORT         (80U)                         // номер порта, который будет использоваться во время первой утановки имени WiFi сети (и пароля), к которой потом будет подключаться лампа в режиме WiFi клиента (лучше не менять)
#define ESP_UDP_PORT          (8888U)                       // номер порта, который будет "слушать" UDP сервер во время работы лампы как в режиме WiFi точки доступа, так и в режиме WiFi клиента (лучше не менять)
#define WIFIMAN_DEBUG         (false)                       // вывод отладочных сообщений при подключении к WiFi сети: true - выводятся, false - не выводятся; настройка не зависит от GENERAL_DEBUG
#define OTA                                                 // если строка не закомментирована, модуль будет ждать два последовательных запроса пользователя на прошивку по воздуху (два четрёхкратных нажатия на кнопку)
#ifdef OTA
#define ESP_OTA_PORT          (8266U)                       // номер порта, который будет "прослушиваться" в ожидании команды прошивки по воздуху
#endif

#define RANDOM_SETTINGS_IN_CYCLE_MODE                       // Строка добавлена для совместимости файлов эффектов с версией  86 в 1 (или уже больше) от Сотнег.                                                             
                                                            // этот режим можно включать/выключать на web странице лампы или "секретной" командой. Не удаляйте и не комментируйте эту строку.
#define USE_RANDOM_SETS_IN_APP                              // Строка добавлена для совместимости файлов эффектов с версией  86 в 1 (или уже больше) от Сотнег.                               
                                                            // Этот режим уже поддерживается приложением от Котейка под Андроид. Не удаляйте и не комментируйте эту строку.
#define SUMMER_HOUR           (3U)                          // час (по зимнему времени!), когда заканчивается зимнее время и начинается летнее; [0..23]
#define SUMMER_WEEK_NUM       (week_t::Last)                // номер недели в месяце, когда происходит переход на летнее время (возможные варианты: First - первая, Second - вторая, Third - третья, Fourth - четвёртая, Last - последняя)
#define SUMMER_WEEKDAY        (dow_t::Sun)                  // день недели, когда происходит переход на летнее время (возможные варианты: Mon - пн, Tue - вт, Wed - ср, Thu - чт, Sat - сб, Sun - вс)
#define SUMMER_MONTH          (month_t::Mar)                // месяц, в котором происходит переход на летнее время (возможные варианты: Jan - январь, Feb - февраль, Mar - март, Apr - апрель, May - май, Jun - июнь, Jul - июль, Aug - август, Sep - сентябрь, Oct - октябрь, Nov - ноябрь, Dec - декабрь)
#define SUMMER_TIMEZONE_NAME  ("EEST")                      // обозначение летнего времени; до 5 символов; может быть использовано, если понадобится его вывести после вывода времени; может быть "ЛЕТ"
#define WINTER_HOUR           (4U)                          // час (по летнему времени!), когда заканчивается летнее время и начинается зимнее; [0..23]
#define WINTER_WEEK_NUM       (week_t::Last)                // номер недели в месяце, когда происходит переход на зимнее время (возможные варианты: First - первая, Second - вторая, Third - третья, Fourth - четвёртая, Last - последняя)
#define WINTER_WEEKDAY        (dow_t::Sun)                  // день недели, когда происходит переход на зимнее время (возможные варианты: Mon - пн, Tue - вт, Wed - ср, Thu - чт, Sat - сб, Sun - вс)
#define WINTER_MONTH          (month_t::Oct)                // месяц, в котором происходит переход на зимнее время (возможные варианты: Jan - январь, Feb - февраль, Mar - март, Apr - апрель, May - май, Jun - июнь, Jul - июль, Aug - август, Sep - сентябрь, Oct - октябрь, Nov - ноябрь, Dec - декабрь)
#define WINTER_TIMEZONE_NAME  ("EET")                       // обозначение зимнего времени; до 5 символов; может быть использовано, если понадобится его вывести после вывода времени; может быть "ЗИМ"

// --- ВНЕШНЕЕ УПРАВЛЕНИЕ --------------
#define USE_MQTT              (true)                       // true - используется mqtt клиент, false - нет
#if USE_MQTT
#define MQTT_RECONNECT_TIME   (10U)                         // время в секундах перед подключением к MQTT брокеру в случае потери подключения
#endif

// --- РАССВЕТ -------------------------
uint8_t DAWN_BRIGHT ;                                       // максимальная яркость рассвета (0-255)
uint8_t DAWN_TIMEOUT;                                       // сколько рассвет светит после времени будильника, минут. Может быть изменено в установках будильника


//#define MAX_UDP_BUFFER_SIZE (UDP_TX_PACKET_MAX_SIZE + 1)
// максимальный размер буффера UDP сервера 
// 255 - это максимальное значение, при котором работа с Избранным не будет глючить
// для исходящих сообщений в приложение данное ограничение можно обойти (см. как реализована отправка "LIST"),
// а для входящего списка избранного - хз. пришлось увеличить до максимально возможножного значения. 
// дальше придётся переделывать типы (размеры) переменных в функциях FavoritesManager.h
#define MAX_UDP_BUFFER_SIZE   (255U)                        // максимальный размер буффера UDP сервера

#define GENERAL_DEBUG_TELNET  (false)                       // true - отладочные сообщения будут выводиться в telnet вместо Serial порта (для удалённой отладки без подключения usb кабелем)
#define TELNET_PORT           (23U)                         // номер telnet порта

#if defined(GENERAL_DEBUG) && GENERAL_DEBUG_TELNET
WiFiServer telnetServer(TELNET_PORT);                       // telnet сервер
WiFiClient telnet;                                          // обработчик событий telnet клиента
bool telnetGreetingShown = false;                           // признак "показано приветствие в telnet"
#define LOG                   telnet
#else
#define LOG                   Serial
#endif

//================ Дальше только для разработчиков. Не меняйте здесь ничего, если не уверены в результате!!! ===================

//#include <EEPROM.h>
//#include "Types.h"
#define EEPROM_PASSWORD_START_ADDRESS           (0U)            // начальный адрес в EEPROM памяти для записи пароля к роутеру
#define EEPROM_MODES_START_ADDRESS              (0x50U)         // начальный адрес в EEPROM памяти для записи настроек эффектов (яркость, скорость, масштаб)
#define EEPROM_FIRST_RUN_ADDRESS                (0x40U)         // (0x40U) адрес в EEPROM памяти для записи признака первого запуска (определяет необходимость первоначальной записи всех хранимых настроек)
#define EEPROM_MODE_STRUCT_SIZE                 (3U)            // 1 байт - яркость; 1 байт - скорость; 1 байт - масштаб
#define EEPROM_TOTAL_BYTES_USED                 (EEPROM_MODES_START_ADDRESS+MODE_AMOUNT*EEPROM_MODE_STRUCT_SIZE+1)       
#define EEPROM_FIRST_RUN_MARK                   (255-MODE_AMOUNT)// число-метка, если ещё не записно в EEPROM_FIRST_RUN_ADDRESS, значит нужно проинициализировать EEPROM и записать все первоначальные настройки
#define EEPROM_WRITE_DELAY                      (30000UL)       // отсрочка записи в EEPROM после последнего изменения хранимых настроек, позволяет уменьшить количество операций записи в EEPROM
#define SAVE_FILE_DELAY_TIMEOUT                 (15000UL)       // отсрочка записи в файл

//+++++Функции для работы с json файлами+++++++++++++++++++++++++++

#include <ArduinoJson.h>        //Установить из менеджера библиотек версию 5.13.5 !!!. https://arduinojson.org/
#ifdef USE_LittleFS
#include <LittleFS.h>    
#define SPIFFS LittleFS  
#endif

String configSetup = "{}";

// Раскоментируйте эти четыре функции и закоментируйте следующие четыре функции если используете библиотеку ArduinoJSON Version 5 (по умолчанию используется Version6)
/*
// ------------- Чтение значения json String
String jsonRead(String &json, String name) {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);
  return root[name].as<String>();
}

// ------------- Чтение значения json int
int jsonReadtoInt(String &json, String name) {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);
  return root[name];
}

// ------------- Запись значения json String
String jsonWrite(String &json, String name, String volume) {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);
  root[name] = volume;
  json = "";
  root.printTo(json);
  return json;
}

// ------------- Запись значения json int
String jsonWrite(String &json, String name, int volume) {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);
  root[name] = volume;
  json = "";
  root.printTo(json);
  return json;
}
*/

// Раскоментируйте эти четыре функции и закоментируйте предыдущие четыре функции если используете библиотеку ArduinoJSON Version 6
// StaticJsonDocument<2048> doc;  // DynamicJsonDocument doc(2048);
// ------------- Чтение значения json String
String jsonRead(String &json, String name) {
  DynamicJsonDocument doc(3072);
  DeserializationError error = deserializeJson(doc, json);
  #ifdef GENERAL_DEBUG
  if (error) {
    LOG.print(F("deserializeJson() failed: "));
    LOG.println(error.f_str());
  }
  #endif
//  deserializeJson(doc, json);
  JsonObject obj = doc.as<JsonObject>();  
  return obj[name].as<String>();
}

// ------------- Чтение значения json int
int jsonReadtoInt(String &json, String name) {
  DynamicJsonDocument doc(3072);
  DeserializationError error = deserializeJson(doc, json);
  #ifdef GENERAL_DEBUG
  if (error) {
    LOG.print(F("deserializeJson() failed: "));
    LOG.println(error.f_str());
  }
  #endif
//  deserializeJson(doc, json);
  return doc[name];
}

// ------------- Запись значения json String
void jsonWrite(String &json, String name, String volume) {
  DynamicJsonDocument doc(3072);
  DeserializationError error = deserializeJson(doc, json);
  #ifdef GENERAL_DEBUG
  if (error) {
    LOG.print(F("deserializeJson() failed: "));
    LOG.println(error.f_str());
  }
  #endif
//  deserializeJson(doc, json);
  doc[name] = volume;
  json = "";
  serializeJson(doc, json);
  //return json;
}

// ------------- Запись значения json int
void jsonWrite(String &json, String name, int volume) {
  DynamicJsonDocument doc(3072);
  DeserializationError error = deserializeJson(doc, json);
  #ifdef GENERAL_DEBUG
  if (error) {
    LOG.print(F("deserializeJson() failed: "));
    LOG.println(error.f_str());
  }
  #endif
//  deserializeJson(doc, json);
  doc[name] = volume;
  json = "";
  serializeJson(doc, json);
  //return json;
}


// ------------- Запись строки в файл
String writeFile(const String& fileName, String& strings ) {
  File configFile = SPIFFS.open("/" + fileName, "w");
  if (!configFile) {
    return "Failed to open config file";
  }
  configFile.print(strings);
  //strings.printTo(configFile);
  configFile.close();
  #ifdef GENERAL_DEBUG
  LOG.print (F("\nСохранён файл "));
  LOG.println (fileName);
  #endif  //GENERAL_DEBUG
  return "Write sucsses";
}
void saveConfig (){
  writeFile(F("config.json"), configSetup );
}
// ------------- Чтение файла в строку
String readFile(const String& fileName, size_t len ) {
  File configFile = SPIFFS.open("/" + fileName, "r");
  if (!configFile) {
    return "Failed";
  }
  size_t size = configFile.size();
  if (size > len) {
    configFile.close();
    return "Large";
  }
  String temp = configFile.readString();
  configFile.close();
  return temp;
}


#if defined(USE_RANDOM_SETS_IN_APP) || defined(RANDOM_SETTINGS_IN_CYCLE_MODE)
void setModeSettings(uint8_t Scale = 0U, uint8_t Speed = 0U);
#endif //#if defined(USE_RANDOM_SETS_IN_APP) || defined(RANDOM_SETTINGS_IN_CYCLE_MODE)

#ifdef USE_MULTIPLE_LAMPS_CONTROL
void multiple_lamp_control ();
bool repeat_multiple_lamp_control = false;
#endif  //USE_MULTIPLE_LAMPS_CONTROL

uint8_t eff_num_correct [MODE_AMOUNT]; //Корректировка номеров эффектов для разных языков
void Display_Timer (uint8_t argument = 0);
void timeTick();
