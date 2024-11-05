#include <Wire.h>

// Declare external C++/C function
extern "C" void print_number_on_serial(uint16_t num);
extern "C" void print_hex_on_serial(byte num);
extern "C" int get_chip_ID();

bool first_time_called_num = true;
void print_number_on_serial(uint16_t num)
{
    if (first_time_called_num)
    {
        // Setup Serial port as this is the first time this function is called
        Serial.begin(115200);
        first_time_called_num = false;
    }
    Serial.print(num);
}

bool first_time_called_hex = true;
void print_hex_on_serial(byte num)
{
    if (first_time_called_hex)
    {
        // Setup Serial port as this is the first time this function is called
        Serial.begin(115200);
        first_time_called_hex = false;
    }
    Serial.println(num, HEX);
}

const byte BNO055 = 0x28;
const byte PAGE = 0x07;

byte read(byte addr, byte reg)
{
    Wire.begin();
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.endTransmission();

    Wire.requestFrom(int(addr), 1);

    byte res;
    while (Wire.available())
    {
        res = Wire.read();
    }

    return res;
}

void setPage(byte addr, byte page)
{
    byte curentPage = read(addr, PAGE);

    if (page != curentPage)
    {
        Wire.begin();
        Wire.beginTransmission(addr);
        Wire.write(PAGE);
        Wire.write(page);
        Wire.endTransmission();
    }
}
bool first_use_Wire = true;

int get_chip_ID()
{
    if (first_use_Wire)
    {
        Wire.begin();
        first_use_Wire = false;
    }
    setPage(BNO055, 0);
    return read(BNO055, 0x00);
}
