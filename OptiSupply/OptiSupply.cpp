#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
#include <limits>
#include <fstream>
using namespace std;

//клас за доставчиците
class Suppliers {
private:
    string bullstat;
    string name;
    string location;
    string phoneNumber;

public:
    // default конструктор
    Suppliers() = default;
    // параметризиран конструктар
    Suppliers(string _bullstat, string _name, string _location, string _phoneNumber) {
        setBullstat(_bullstat);
        setName(_name);
        setLocation(_location);
        setPhoneNumber(_phoneNumber);
    }
    //копиращ(copy) конструктор
    Suppliers(const Suppliers& supplier) :
        bullstat(supplier.bullstat), name(supplier.name), location(supplier.location), phoneNumber(supplier.phoneNumber) {}

    //getters
    string getBullstat() {
        return bullstat;
    }

    string getName() {
        return name;
    }

    string getLocation() {
        return location;
    }

    string getPhoneNumber()
    {
        return phoneNumber;
    }

    //setters с проверки за валидност на данните
    bool setBullstat(string _bullstat)
    {
        // 1) Проверка за дължина
        if (_bullstat.size() != 9) {
            cout << "Incorrect bullstat (must be 9 digits)!" << endl;
            return false;
        }

        // 2) Проверка дали всички символи са цифри
        for (char ch : _bullstat) {
            if (ch < '0' || ch > '9') {
                cout << "Incorrect bullstat (must contain only digits)!" << endl;
                return false;
            }
        }

        bullstat = _bullstat;
        return true;
    }

    void setName(string _name)
    {
        name = _name;
    }

    void setLocation(string _location)
    {
        location = _location;
    }

    bool setPhoneNumber(string _phoneNumber)
    {
        // 1) Проверка за дължина
        if (_phoneNumber.size() != 10) {
            cout << "Incorrect phone number (must be 10 digits)!" << endl;
            return false;
        }

        // 2) Проверка дали всички символи са цифри
        for (char ch : _phoneNumber) {
            if (ch < '0' || ch > '9') {
                cout << "Incorrect phone number (must contain only digits)!" << endl;
                return false;
            }
        }

        phoneNumber = _phoneNumber;
        return true;
    }

    // предефиниране на оператор << за извеждане на доставчик
    friend ostream& operator<<(ostream& os, const Suppliers& s) {
        os << "Supplier: " << s.name
            << ", Bullstat: " << s.bullstat
            << ", Location: " << s.location
            << ", Phone: " << s.phoneNumber;
        return os;
    }
};

// клас за типовете оптични материали
enum class OpticType {
    Spherical,    // сферични лещи
    Cylindrical,  // цилиндрични (за астигматизъм)
    Bifocal,      // бифокални
    Progressive,  // прогресивни
    Contact       // контактни лещи
};

// клас за оптичните материали
class OpticalItem {
private:
    OpticType type;
    double thickness;
    double diopter;
    string materialName;
    double price;
public:
    // default конструктор
    OpticalItem() = default;
    // параметризиран конструктар
    OpticalItem(OpticType _type, double _thickness, double _diopter, string _materialName, double _price) {
        setType(_type);
        setThickness(_thickness);
        setDiopter(_diopter);
        setMaterialName(_materialName);
        setPrice(_price);
    }
    //копиращ(copy) конструктор
    OpticalItem(const OpticalItem& items) :
        type(items.type), thickness(items.thickness), diopter(items.diopter), materialName(items.materialName), price(items.price) {
    }

    //getters
    OpticType getType() {
        return type;
    }

    double getThickness() {
        return thickness;
    }

    double getDiopter() {
        return diopter;
    }

    string getMaterialName() {
        return materialName;
    }
    double getPrice() {
        return price;
    }

    //setters с проверки за валидност на данните
    void setType(OpticType _type) {
        type = _type;
    }

    bool setThickness(double _thickness) {
        if (_thickness <= 0) {
            cout << "Incorrect thickness (must be > 0)!" << endl;
            return false;
        }
        thickness = _thickness;
        return true;
    }

    bool setDiopter(double _diopter) {
        if (_diopter < -20 || _diopter > 20) {
            cout << "Incorrect diopter (must be between -20 and 20)!" << endl;
            return false;
        }
        diopter = _diopter;
        return true;
    }

    void setMaterialName(string _materialName)
    {
        materialName = _materialName;
    }

    bool setPrice(double _price) {
        if (_price <= 0) {
            cout << "Incorrect price (must be > 0)!" << endl;
            return false;
        }
        price = _price;
        return true;
    }
    // предефинираме оператор << за да може да се изведът типовете с думи, а не с индексите им
    friend ostream& operator<<(ostream& os, OpticalItem item) {
        string typeName;

        switch (item.type) {
        case OpticType::Spherical:
            typeName = "Spherical";
            break;
        case OpticType::Cylindrical:
            typeName = "Cylindrical";
            break;
        case OpticType::Bifocal:
            typeName = "Bifocal";
            break;
        case OpticType::Progressive:
            typeName = "Progressive";
            break;
        case OpticType::Contact:
            typeName = "Contact";
            break;
        default:
            typeName = "Unknown";
            break;
        }

        // предефиниране на оператор << за извеждане на оптичните материали
        os << "Material: " << item.materialName
            << ", Type: " << typeName
            << ", Diopter: " << item.diopter
            << ", Thickness: " << item.thickness
            << ", Price: $" << fixed << setprecision(2) << item.price;


        return os;
    }

};

// клас за датата на поръчка
class Date {
private:
    int day, month, year;

public:
    // default конструктор
    Date() : day(1), month(1), year(2000) {}
    // параметризиращ конструктор
    Date(int d, int m, int y) {
        setDay(d);
        setMonth(m);
        setYear(y);
    }
    // копиращ конструктор
    Date(const Date& date) : day(date.day), month(date.month), year(date.year) {}

    // getters
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }

    // setters с проверки за валидност на данните
    bool setDay(int d) {
        if (d < 1 || d > 31) {
            cout << "Invalid day!" << endl;
            return false;
        }
        day = d;
        return true;
    }

    bool setMonth(int m) {
        if (m < 1 || m > 12) {
            cout << "Invalid month!" << endl;
            return false;
        }
        month = m;
        return true;
    }

    bool setYear(int y) {
        if (y < 1900) {
            cout << "Invalid year!" << endl;
            return false;
        }
        year = y;
        return true;
    }

    void printDate() const {
        cout << day << "/" << month << "/" << year;
    }
};

//клас за поръчки
class Order {
private:
    int orderID;
    Suppliers supplier;
    vector<OpticalItem> items;
    vector<int> quantities;
    double totalPrice;
    Date orderDate;
public:
    // default конструктор
    Order() : orderID(0), totalPrice(0.0) {}
    // параметризиращ конструктор
    Order(int _orderID, Suppliers _supplier, Date _orderDate) : orderID(0), totalPrice(0.0)
    {
        setOrderID(_orderID);
        setSupplier(_supplier);
        setOrderDate(_orderDate);
    }
    // копиращ конструктор
    Order(const Order& orders) :orderID(orders.orderID), supplier(orders.supplier), items(orders.items), quantities(orders.quantities),
        totalPrice(orders.totalPrice), orderDate(orders.orderDate) {
    }

    //getters
    int getOrderID() {
        return orderID;
    }
    Suppliers getSupplier() {
        return supplier;
    }
    Date getOrderDate() {
        return orderDate;
    }
    double getTotalPrice() {
        return totalPrice;
    }
    int getItemsCount() {
        return items.size();
    }

    //setters с проверки за валидност на данните
    void setOrderID(int _orderID) {
        if (_orderID <= 0) {
            cout << "Order ID must be > 0!" << endl;
            return;
        }
        orderID = _orderID;
    }

    void setSupplier(Suppliers _supplier) {
        supplier = _supplier;
    }

    void setOrderDate(Date _orderDate) {
        orderDate = _orderDate;
    }

    // добавяне на материал и количеството към поръчката
    // сумиране на обща сума на поръчката
    void addItem(OpticalItem item, int quantity) {
        if (quantity <= 0) {
            cout << "Quantity must be > 0!" << endl;
            return;
        }
        items.push_back(item);
        quantities.push_back(quantity);
        totalPrice += item.getPrice() * quantity;
    }


    // предефиниране на оператор << за отпечатване на поръчка
    friend ostream& operator<<(ostream& os, const Order& order) {
        os << "Order ID: " << order.orderID << "\n";
        os << order.supplier << "\n";
        os << "Order date: ";
        order.orderDate.printDate();
        os << "\n";
        os << "Total price: $" << fixed << setprecision(2) << order.totalPrice << "\n";
        return os;
    }
};

// Функция за проверка на невалиден вход
bool validateInput() {
    if (cin.fail()) {
        cin.clear();  // Изчистваме буфера
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Игнорираме невалидните символи
        cout << "Invalid input! Please enter a valid number." << endl;
        return false;  // Връщаме false, ако входът е невалиден
    }
    return true;  // Връщаме true, ако входът е валиден
}

// функция за запис на доставчиците във файл
void saveSuppliersToFile(const vector<Suppliers>& suppliers) {
    ofstream file("suppliers.txt", ios::trunc);

    if (!file.is_open()) {
        cout << "Failed to open file for writing!" << endl;
        return;
    }

    for (const auto& supplier : suppliers) {
        file << supplier << endl;  // Използваме оператор << за запис
    }
    file.close();  // Затваряме файла
}

// Функция за запис на оптични материали в файл
void saveOpticalItemsToFile(const vector<OpticalItem>& opticalItems) {
    ofstream file("optical_items.txt", ios::trunc);  // Използваме trunc за презаписване на файла

    if (!file.is_open()) {
        cout << "Failed to open file for writing!" << endl;
        return;
    }

    // Записваме всички елементи в един цикъл
    for (const auto& item : opticalItems) {
        file << item << endl;  // Записваме елементите с оператора <<
    }

    file.close();  // Затваряме файла
}


// Функция за запис на поръчки в файл
void saveOrdersToFile(const vector<Order>& orders) {
    ofstream file("orders.txt", ios::trunc);

    if (!file.is_open()) {
        cout << "Failed to open file for writing!" << endl;
        return;
    }

    for (const auto& order : orders) {
        file << order << endl; 
    }
    file.close();
}

int main()
{
    vector<Suppliers> suppliers;
    vector<OpticalItem> opticalItems;
    vector<Order> orders;
    int choice;
    int nextOrderId = 1;
    while (true) {
        cout << "---Menu---\n" << endl;
        cout << "1. Add supplier\n";
        cout << "2. List suppliers\n";
        cout << "3. Add optical item\n";
        cout << "4. List optical items\n";
        cout << "5. Create order\n";
        cout << "6. List orders\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        if (choice == 0) {
            cout << "Exititng the program!";
            break;
        }
        else if (choice == 1) {
            // добавяме данни за доставчик
            Suppliers s;

            string bullstat;
            while (true) {
                cout << "Enter bullstat (9 digits): ";
                cin >> bullstat;
                if (s.setBullstat(bullstat)) break;  // ако е валиден илизаме от цикъла
            }

            string name;
            cout << "Enter supplier name: ";
            cin.ignore();
            getline(cin, name); // чете целия ред, дори да има спейсове
            s.setName(name);

            string location;
            cout << "Enter location: ";
            getline(cin, location);
            s.setLocation(location);

            string phone;
            while (true) {
                cout << "Enter phone (10 digits): ";
                cin >> phone;
                if (s.setPhoneNumber(phone)) break;
            }

            suppliers.push_back(s);
            cout << "Supplier added!\n";
            saveSuppliersToFile(suppliers);
        }
        else if (choice == 2)
        {
            if (suppliers.empty())
            {
                cout << "There are no suppliers in the list!\n";
            }
            else {
                cout << "Suppliers:\n";
                for (int i = 0; i < suppliers.size(); i++)
                {
                    cout << i << ")" << suppliers[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            OpticalItem item;
            int typeChoice;
            while (true)
            {
                cout << "Choose optic type:\n";
                cout << "0 - Spherical\n";
                cout << "1 - Cylindrical\n";
                cout << "2 - Bifocal\n";
                cout << "3 - Progressive\n";
                cout << "4 - Contact\n";
                cout << "Type(0-4): ";
                cin >> typeChoice;
                if (cin.fail() || typeChoice < 0 || typeChoice > 4) {
                    cin.clear();  // Изчистваме failbit
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Игнорираме останалите символи
                    cout << "Invalid type choice! Please enter a number between 0 and 4.\n";
                }
                else {
                    OpticType type;
                    switch (typeChoice) {
                    case 0:
                        type = OpticType::Spherical;
                        break;
                    case 1:
                        type = OpticType::Cylindrical;
                        break;
                    case 2:
                        type = OpticType::Bifocal;
                        break;
                    case 3:
                        type = OpticType::Progressive;
                        break;
                    case 4:
                        type = OpticType::Contact;
                        break;
                    }
                    item.setType(type);
                    break;
                }
            }

            double thickness;

            while (true) {
                cout << "Enter thickness (>0): ";
                cin >> thickness;

                // Извикваме validateInput() за проверка на входа
                if (!validateInput()) {
                    continue;  // Ако входът е невалиден, продължаваме с ново въвеждане
                }
                if (item.setThickness(thickness)) break;
            }

            double diopter;
            while (true) {
                cout << "Enter diopter (between -20 and 20): ";
                cin >> diopter;
                if (!validateInput()) {
                    continue; 
                }
                if (item.setDiopter(diopter)) break;
            }

            string materialName;
            cout << "Enter material name: ";
            cin.ignore();
            getline(cin, materialName);
            item.setMaterialName(materialName);

            double price;
            while (true) {
                cout << "Enter price (>0): ";
                cin >> price;
                if (!validateInput()) {
                    continue;
                }
                if (item.setPrice(price)) break;
            }

            opticalItems.push_back(item);
            cout << "Optical item added!\n";
            saveOpticalItemsToFile(opticalItems);
        }
        else if (choice == 4) {
            // Списък с оптични материали
            if (opticalItems.empty()) {
                cout << "There are no optical items in the list!\n";
            }
            else {
                cout << "Optical items:\n";
                for (int i = 0; i < opticalItems.size(); i++) {
                    cout << i << ") " << opticalItems[i] << endl;
                }
            }
        }
        else if (choice == 5) {
            // Създаване на поръчка
            if (suppliers.empty()) {
                cout << "No suppliers. Add suppliers first.\n";
                continue;
            }
            if (opticalItems.empty()) {
                cout << "No optical items. Add items first.\n";
                continue;
            }

            cout << "Suppliers:\n";
            for (int i = 0; i < suppliers.size(); i++) {
                cout << i << ") " << suppliers[i] << endl;
            }

            int supIndex;
            while (true) {
                cout << "Choose supplier index: ";
                cin >> supIndex;

                if (!validateInput()) {
                    continue;
                }

                if (supIndex < 0 || supIndex >= (int)suppliers.size()) {
                    cout << "Invalid supplier index! Please enter a valid index.\n";
                }
                else {
                    break;
                }
            }

            Suppliers chosenSupplier = suppliers[supIndex];

            // Въвеждане на дата за поръчката
            int d, m, y;
            Date orderDate;
            while (true) {
                cout << "Enter order date (day month year): ";
                cin >> d >> m >> y;
                if (!validateInput()) {
                    continue;
                }
                if (orderDate.setDay(d) && orderDate.setMonth(m) && orderDate.setYear(y)) {
                    break;
                }
            }
            // Създаваме поръчка
            Order order(nextOrderId, chosenSupplier, orderDate);
            nextOrderId++;
            // Дали потребителя ще въвежда още продукти или не
            char more = 'y';
            while (more == 'y' || more == 'Y') {
                cout << "Optical items:\n";
                for (int i = 0; i < opticalItems.size(); i++) {
                    cout << i << ") " << opticalItems[i] << endl;
                }
                int itemIndex;
                while (true) {  // Безкраен цикъл за индекса на продукта
                    cout << "Choose optical item index: ";
                    cin >> itemIndex;
                    if (!validateInput()) {
                        continue;
                    }
                    if (itemIndex < 0 || itemIndex >= (int)opticalItems.size()) {
                        cout << "Invalid item index! Please choose a valid index.\n";
                    }
                    else {
                        break;
                    }
                }

                int qty;
                while (true) {  // Безкраен цикъл за количеството
                    cout << "Enter quantity: ";
                    cin >> qty;
                    if (!validateInput()) {
                        continue;
                    }
                    if (qty <= 0) {
                        cout << "Invalid quantity! Quantity must be greater than 0.\n";
                    }
                    else {
                        break; 
                    }
                }
                order.addItem(opticalItems[itemIndex], qty);

                cout << "Add more items to this order? (y/n): ";
                cin >> more;
            }
            cout << "\nFINAL ORDER\n";
            cout << order << endl;
            orders.push_back(order);
            saveOrdersToFile(orders);
        }
        else if (choice == 6) {
            // Списък с поръчки
            if (orders.empty()) {
                cout << "There are no orders in the list!\n";
            }
            else {
                cout << "Orders:\n";
                for (int i = 0; i < (int)orders.size(); i++) {
                    cout << i << ") " << orders[i] << endl;
                }
            }
        }

        else {
            cout << "Invalid choice!\n";
        }
    }
}
