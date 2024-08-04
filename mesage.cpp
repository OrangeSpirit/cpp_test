#include <iostream>
  
// класс сообщения
class Message
{
public:
    // обычный конструктор
    Message(const char* data, unsigned count)
    {
        size = count;
        text = new char[size];  // выделяем память
        for(unsigned i{}; i < size; i++)    // копируем данные
        {
            text[i] = data[i];
        }
 
        id = ++counter;
        std::cout << "Create Message " << id << std::endl;
    }
    // конструктор копирования
    Message(const Message& copy) : Message{copy.getText(), copy.size }  // обращаемся к стандартному конструктору
    {
        std::cout << "Copy  Message " << copy.id << " to " << id << std::endl;
    }
     
    // деструктор
    ~Message()
    { 
        std::cout << "Delete Message "  << id << std::endl;
        delete[] text;  // особождаем память
    }
    char* getText() const { return text; }
    unsigned getSize() const { return size; }
    unsigned getId() const {return id;}
private:
    char* text{};  // текст сообщения
    unsigned size{};    // размер сообщения
    unsigned id{};  // номер сообщения
    static inline unsigned counter{};   // статический счетчик для генерации номера объекта
};
 
// класс мессенджера, который отправляет сообщение
class Messenger
{
public:
    Messenger(Message mes): message{mes}
    { }
    void sendMessage() const
    {
        std::cout << "Send message " <<  message.getId() << ": " << message.getText() << std::endl;
    }
private:
    Message message;
};
int main()
{
    Messenger telegram{Message{"param pum pum", 1199}};
    telegram.sendMessage();
}

// #include <iostream>
  
// // класс сообщения
// class Message
// {
// public:
//     // обычный конструктор
//     Message(const char* data, unsigned count)
//     {
//         size = count;
//         text = new char[size];  // выделяем память
//         for(unsigned i{}; i < size; i++)    // копируем данные
//         {
//             text[i] = data[i];
//         }
 
//         id = ++counter;
//         std::cout << "Create Message " << id << std::endl;
//     }
//     // конструктор копирования
//     Message(const Message& copy) : Message{copy.getText(), copy.size }  // обращаемся к стандартному конструктору
//     {
//         std::cout << "Copy  Message " << copy.id << " to " << id << std::endl;
//     }
//     Message(Message&& moved)
//     {
//         id = ++counter;
//         std::cout << "Create Message " << id << std::endl;
 
//         text = moved.text;  // перемещаем текст сообщения
//         size = moved.size;  // перемещаем размер сообщения
//         moved.text = nullptr;
//         std::cout << "Move Message " << moved.id << " to " << id << std::endl;
//     }
//     // деструктор
//     ~Message()
//     { 
//         std::cout << "Delete Message "  << id << std::endl;
//         delete[] text;  // особождаем память
//     }
//     char* getText() const { return text; }
//     unsigned getSize() const { return size; }
//     unsigned getId() const {return id;}
// private:
//     char* text{};  // текст сообщения
//     unsigned size{};    // размер сообщения
//     unsigned id{};  // номер сообщения
//     static inline unsigned counter{};   // статический счетчик для генерации номера объекта
// };
 
// // класс мессенджера, который отправляет сообщение
// class Messenger
// {
// public:
//     Messenger(Message mes): message{std::move(mes)}
//     { }
//     void sendMessage() const
//     {
//         std::cout << "Send message " <<  message.getId() << ": " << message.getText() << std::endl;
//     }
// private:
//     Message message;
// };
// int main()
// {
//     Messenger telegram{Message{"Hello Word", 11}};
//     telegram.sendMessage();
// }