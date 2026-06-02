// #include "json.hpp"
// using json = nlohmann::ordered_json;
// #include <iostream>
// #include "fstream"
// #include <string>
// using namespace std;
// class Book
// {
//     string name;
//     string authorName;
//     string dateOfPublish;
//   static  int bookCount;
//     bool IsBorrow;

// public:
//     Book()
//     {
        
//         IsBorrow = false;
//     }
//     Book(string n, string a, string d)
//     {
//         name = n;
//         authorName = a;
//         dateOfPublish = d;
//         bookCount++;
//     }

//     string getName()
//     {
//         return name;
//     }
//     void setBorrowed(bool borrow)
//     {
//         IsBorrow = borrow;
//     }
//     string getAuthorName()
//     {
//         return authorName;
//     }
//     string getDateOfPublish()
//     {
//         return dateOfPublish;
//     }
//     int getBookCount()
//     {
//         return bookCount;
//     }
//     bool getBorrowed() { return IsBorrow; }
//     json tojson(){
//         json j;
//         j["BookName"]=name;
//         j["BookAuthor"]=authorName;
//         j["dataOfPublish"]=dateOfPublish;
//         j["IsBorrowed"]=IsBorrow;
//         return j;

//     }


//     void fromJson(json&j){
//         name=j["BookName"];
//         authorName=j["BookAuthor"];
//         dateOfPublish=j["dataOfPublish"];
//         IsBorrow=j["IsBorrowed"];
//     }
//     friend  ostream&operator <<(ostream&os,Book*b){
//         os<<"Book Name: "<<b->getName()<<endl;
//         os<<"Book Author: "<<b->getAuthorName()<<endl;
//         os<<"Book Published Date: "<<b->getDateOfPublish()<<endl;
//         os<<"Total Books In Liberary: "<<b->getBookCount()<<endl;
//         os<<"=================\n";
//         return os;

//     }
// };
// int Book::bookCount=0;
// class student
// {
//     Book *book;
//     string BookName;
//     string name;
//     string id;
//     int marks;

// public:
//     student(string n, string bN, string i, int mr)

//     {
//         BookName = bN;
//         name = n;
//         id = i;
//         marks = mr;
//         book=nullptr;
//     }

//     string getName()
//     {
//         return name;
//     }
//     string getID()
//     {
//         return id;
//     }

//     int getMarks()
//     {
//         return marks;
//     }

//     void BorrowBook(Book *b)
//     {
//         if (b->getName() == BookName && !b->getBorrowed())
//         {
//             book = b;
//             book->setBorrowed(true);
//             cout << "Book borrowed successfully!" << endl;
//         }
//         else
//         {
//             cout << "Book not available!" << endl;
//         }
//     }

//     int operator+(student &other)
//     {
        
//         return marks + other.marks;
//     }
//     json toJson()
//     {
//         json j;
//         j["name"] = name;
//         j["id"] = id;
//         j["marks"] = marks;
       
//         if(book!=nullptr){

       
//     json bookJson=json::array();
   
//         bookJson.push_back(book->tojson());

    
//     j["BooksData"]=bookJson;
        
//     }
//     return j;
//     }
//     void fromJson(json &j)
//     {

//         name = j["name"];
//         id = j["id"];
//         marks = j["marks"];
//         for(auto &books:j["BooksData"]){
//             Book*b1=new Book("","","");
//             b1->fromJson(books);

//         }
//         return;
//     }
//     friend ostream &operator<<(ostream &os, student &data)
//     {
//         os << "Name: " << data.getName() << endl;
//         os << "ID: " << data.getID() << endl;
//         os << "Marks: " << data.getMarks() << endl;
//         if(data.book != nullptr)
//        os << "Boorrow Book Name: " << data.book->getName() << endl;
//        else
//        os << "Boorrow Book Name: None (not borrowed)" << endl;
//         os << "==================\n";
//         return os;
//     }
// };

// class Liberary
// {
//     static Liberary *instance;

//     int count;
//     int capacity;
//     student *s[10];
//     Book book;
//     string name;
//     Liberary()
//     {
//         count = 0;
//         capacity = 5;
//         for (int i = 0; i < 10; i++)
//         {
//             s[i] = nullptr;
//         }
//     }

// public:
//     ~Liberary()
//     {
//         for (int i = 0; i < count; i++)
//             delete s[i];
//     }
//     static Liberary &getInstance()
//     {
//         static Liberary instance;
//         return instance;
//     }
//     void addStudent(student *st)
//     {
//         if (count < 10)
//         {
//             s[count++] = st;
//         }
//     }
//     void Details()
//     {

//         for (int i = 0; i < count; i++)
//         {

//             if (s[i] != nullptr)
//                 cout<<*s[i] << endl;
//         }
//     }

//     void saveToFile()
//     {
//         ofstream write("liberary.json");

//         try
//         {
//             if (write)
//             {
//                 json j;
//                 j["student"] = json::array();
//                 for (int i = 0; i < count; i++)
//                 {
//                     if (s[i] != nullptr)
//                         j["student"].push_back(s[i]->toJson());
//                 }

//                 write << j.dump(4);
//                 write.close();
//             }
//         }
//         catch (exception *e)
//         {
//             cout << "Error" << e->what() << endl;
//         }
//     }

//     void loadFromFile()
//     {
//         ifstream read("liberary.json");
//         try
//         {
//             json j;
//             read >> j;

//             read.close();
//             for (auto &stud : j["student"])
//             {
//                 student *s1 = new student("", "", "", 0);
//                 s1->fromJson(stud);
//                 s[count++]=s1;
//             }
//         }
//         catch (exception *e)
//         {
//             cout << "Erro in file " << e->what() << endl;
//         }
//     }
// };

// Liberary *Liberary::instance = nullptr;
// int main()
// {
//     Liberary &lib = Liberary::getInstance();

//     cout << "\n========================================" << endl;
//     cout << "     LIBRARY MANAGEMENT SYSTEM" << endl;
//     cout << "========================================" << endl;

//     // Create books
//     Book book1("C++ Programming", "Bjarne Stroustrup", "1985");
//     Book book2("Data Structures", "Robert Lafore", "1999");
//     Book book3("Design Patterns", "Erich Gamma", "1994");
//     Book book4("Clean Code", "Robert Martin", "2008");

//     // Display books
//     cout << "\n--- Available Books ---" << endl;
//     cout << &book1;
//     cout << &book2;
//     cout << &book3;
//     cout << &book4;

//     // Create students
//     student *s1 = new student("Ali", "C++ Programming", "S001", 95);
//     student *s2 = new student("Bob", "Data Structures", "S002", 87);
//     student *s3 = new student("Charlie", "Design Patterns", "S003", 92);
//     student *s4 = new student("Diana", "C++ Programming", "S004", 88);
//     student *s5 = new student("Eve", "Clean Code", "S005", 91);

//     // Add students to library
//     cout << "\n--- Adding Students to Library ---" << endl;
//     lib.addStudent(s1);
//     lib.addStudent(s2);
//     lib.addStudent(s3);
//     lib.addStudent(s4);
//     lib.addStudent(s5);
//     cout << "5 students added successfully!" << endl;

//     // Borrow books
//     cout << "\n--- Borrowing Books ---" << endl;
//     s1->BorrowBook(&book1);  // Ali borrows C++ Programming
//     s2->BorrowBook(&book2);  // Bob borrows Data Structures
//     s3->BorrowBook(&book3);  // Charlie borrows Design Patterns
//     s4->BorrowBook(&book1);  // Diana tries to borrow C++ Programming (already borrowed)
//     s5->BorrowBook(&book4);  // Eve borrows Clean Code

//     // Display all student details
//     cout << "\n--- All Student Details (Using operator<<) ---" << endl;
//     lib.Details();

//     // Test operator overloading
//     cout << "\n--- Operator Overloading (+) ---" << endl;
//     int totalMarks = *s1 + *s2;
//     cout << "Sum of Ali and Bob's marks: " << totalMarks << endl;
    
//     totalMarks = *s3 + *s5;
//     cout << "Sum of Charlie and Eve's marks: " << totalMarks << endl;
    
//     totalMarks = *s1 + *s3 + s5->getMarks();
//     cout << "Sum of Ali, Charlie and Eve's marks: " << totalMarks << endl;

//     // Save to JSON file
//     cout << "\n--- Saving to JSON File ---" << endl;
//     lib.saveToFile();
//     cout << "Data saved to 'liberary.json'" << endl;

//     // Display JSON structure (optional - shows what was saved)
//     cout << "\n--- JSON File Content Preview ---" << endl;
//     ifstream read("liberary.json");
//     string content;
//     if (read.is_open()) {
//         getline(read, content);
//         cout << content.substr(0, 200) << "..." << endl;
//         read.close();
//     }

//     // Load from file into new library instance
//     cout << "\n--- Loading from JSON File ---" << endl;
//     Liberary &lib2 = Liberary::getInstance();
//     lib2.loadFromFile();
    
//     // Display loaded data
//     cout << "\n--- Loaded Student Details ---" << endl;
//     lib2.Details();

//     // Show individual student info (using operator<< directly)
//     cout << "\n--- Individual Student Info ---" << endl;
//     cout << *s1;
//     cout << *s3;
//     cout << *s5;

//     // Show book status after borrowing
//     cout << "\n--- Book Status After Borrowing ---" << endl;
//     cout << "Book1 (C++ Programming) borrowed status: " << (book1.getBorrowed() ? "Borrowed" : "Available") << endl;
//     cout << "Book2 (Data Structures) borrowed status: " << (book2.getBorrowed() ? "Borrowed" : "Available") << endl;
//     cout << "Book3 (Design Patterns) borrowed status: " << (book3.getBorrowed() ? "Borrowed" : "Available") << endl;
//     cout << "Book4 (Clean Code) borrowed status: " << (book4.getBorrowed() ? "Borrowed" : "Available") << endl;

//     // Test total book count (static variable)
//     cout << "\n--- Total Books in Library (Static Count) ---" << endl;
//     cout << "Total books created: " << book1.getBookCount() << endl;
//     cout << "(Note: This counts all Book objects created)" << endl;

//     // Clean up (optional - destructor will handle)
//     cout << "\n--- Program End ---" << endl;

//     return 0;
// }


// #include <iostream>

// class SmartVector {
// private:
//     double x; // 
//     double y; // 

// public:
//     // Constructor with default arguments 
//     SmartVector(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {} // 

//     // Overload + operator as member function 
//     SmartVector operator+(const SmartVector& other) const { // 
//         // SmartVector val=x+other.x;
//         // SmartVector val2=y+other.y;
//         // return val,val2;
//         return {this->x + other.x, this->y + other.y};
//     }

//     // Overload == operator as member function 
//     bool operator==(const SmartVector& other) const { // 
//         return {this->x == other.x && this->y == other.y};
//     }

//     // Overload << operator using a friend function 
//     friend std::ostream& operator<<(std::ostream& out, const SmartVector& v) { // 
//         out << "(" << v.x << ", " << v.y << ")";
//         return out;
//     }
// };

// int main() {
//     SmartVector v1(3.5, 4.5);
//     SmartVector v2(1.5, 2.5);
//     SmartVector v3 = v1 + v2;

//     std::cout << "v1: " << v1 << "\n";
//     std::cout << "v2: " << v2 << "\n";
//     std::cout << "v3 (v1 + v2): " << v3 << "\n";
//     std::cout << "Is v1 == v2?: " << (v1 == v2 ? "True" : "False") << "\n";

//     return 0;
// }
    



// #include <iostream>
// #include <string>

// class Logger {
// private:
//     std::string logStorage[100]; // Static sizing buffer limit encapsulation constraint [cite: 11]
//     int totalLogs;
    
//     // Singleton Architecture: Keep constructor private to block external instantiations [cite: 10]
//     Logger() : totalLogs(0) {} // [cite: 11]

//     // Disable assignment operator and copy configurations to lock instance creation [cite: 10]
//     Logger(const Logger&) = delete;
//     Logger& operator=(const Logger&) = delete;

// public:
//     // Interface to get the single shared instance pointer [cite: 10, 12]
//     static Logger&getInstance() {
//         static Logger sharedSystemLoggerInstance; // Thread-safe local static object initialization
//         return sharedSystemLoggerInstance;
//     }

//     void addLog(const std::string& systemMessage) { // [cite: 12]
//         if (totalLogs < 100) {
//             logStorage[totalLogs] = systemMessage;
//             totalLogs++;
//         } else {
//             std::cout << "Buffer array saturation reached.\n";
//         }
//     }

//     void displayAllLogs() const { // [cite: 12]
//         std::cout << "=== CURRENT LOGS BUFFER ===\n";
//         for (int i = 0; i < totalLogs; i++) {
//             std::cout << "[" << i << "] -> " << logStorage[i] << "\n";
//         }
//     }
// };

// // Simulation modules tracking system operations [cite: 8, 13]
// void executeAuthenticationModule() {
//     Logger& logInterface = Logger::getInstance(); // [cite: 12]
//     logInterface.addLog("Auth success tracking for user admin."); // [cite: 8, 12]
// }

// void executeDatabaseModule() {
//     Logger& logInterface = Logger::getInstance(); // [cite: 12]
//     logInterface.addLog("Database write operation finalized securely."); // [cite: 8, 12]
// }

// int main() { // [cite: 13]
//     Logger::getInstance().addLog("System Initialization Routine started."); // [cite: 13]
    
//     executeAuthenticationModule(); // [cite: 13]
//     executeDatabaseModule();       // [cite: 13]
    
//     // Fetch instance directly to dump unified diagnostic trace records [cite: 12]
//     Logger& centralDiagnosticPointer = Logger::getInstance();
//     centralDiagnosticPointer.displayAllLogs(); // [cite: 12]
    
//     return 0;
// }



// #include <iostream>
// using namespace std;

// class A {
// public:
//     A() { cout << "A "; }
//    virtual  ~A() { cout << "~A "; }

//     virtual void func() { cout << "A func "; }
// };

// class B : public A {
// public:
//     B() { cout << "B "; }
//     ~B() { cout << "~B "; }

//     void func() { cout << "B func "; }
// };

// class C : public B {
// public:
//     C() { cout << "C "; }
//     ~C() { cout << "~C "; }

//     void func() { cout << "C func "; }
// };

// int main() {
//     // A* ptr = new C();

//     // ptr->func();
//     // delete ptr;

//     A obj = C();
// obj.func();

// }





#include <iostream>
using namespace std;

// class A {
// public:
//     int* x;
// public:
//     A(int v = 1) {
//         x = new int(v);
//         cout << "A" << *x << " ";
//     }

//     A(const A& other) {
//         x = new int(*other.x);
//         cout << "AC" << *x << " ";
//     }

//     virtual void f() {
//         cout << "Af ";
//     }

//     virtual A& operator+=(const A& other) {
//         *x += *other.x;
//         cout << "A+= ";
//         return *this;
//     }

//     virtual ~A() {
//         cout << "~A" << *x << " ";
//         delete x;
//     }
// };

// class B : public A {
// public:

//     B(int v = 2) : A(v) {
//         cout << "B ";
//     }

//     void f() {
//         cout << "Bf ";
//     }

//     B& operator+=(const A& other) {
//         *x += (*other.x) * 2;
//         cout << "B+=" << *x <<endl;
//         return *this;
//     }

//     ~B() {
//         cout << "~B ";
//     }
// };	

// int main() {
//     B b1(3);
//     B b2 = b1;

//     A* ptr = &b1;
//     ptr->f();

//     b1 += b2;

//     A obj = b1;
//     obj.f();

//     return 0;
// }	


class matrix{
int **data;
int size;
public:
matrix(int z){
    size=z;

   data=nullptr;
   data=new int*[size];
   for (int i = 0; i < size; i++) {
            data[i] = new int[size](); // The () automatically sets everything to 0
        }
}
~matrix(){
    for (int i = 0; i < size; i++)
    {
        delete[]data[i];
            
    }
    delete[]data;
    
}
matrix(const matrix &other){
    size=other.size;
    data=new int*[size];
    for(int i=0;i<size;i++){
        data[i]=new int[size];
        for(int j=0;j<size;j++){
            data[i][j]=other.data[i][j];
        }
    }
}

bool operator ==(const matrix other){
    return {size==other.size};
}
friend istream& operator>>(istream&in,matrix &m){
    for(int i=0;i<m.size;i++){
        for(int j=0;j<m.size;j++ ){
            in>>m.data[i][j];
        }
    }
return in;
}
friend ostream& operator<<(ostream&out,matrix &m){
    for(int i=0;i<m.size;i++){
        for(int j=0;j<m.size;j++ ){
            out<<m.data[i][j]<<"\t";
        }
        cout<<endl;
    }

    
return out;
}

matrix operator +(matrix&other){
    matrix result(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
     result.data[i][j]=data[i][j]+other.data[i][j];
        }
    }
return result;
}
matrix operator -(matrix&other){
    matrix result(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
     result.data[i][j]=data[i][j]-other.data[i][j];
        }
    }
return result;
}
matrix operator *(matrix&other){
    matrix result(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            result.data[i][j]=0;
            for(int k=0;k<size;k++)
     result.data[i][j]+=data[i][k]*other.data[k][j];
        }
    }
return result;
}
matrix operator=(matrix &other){
    if(this==&other)return *this;
    for(int i=0;i<size;i++){
        delete[]data[i];
    }
    delete[]data;
    size=other.size;
    // Copy from other
    size = other.size;
    data = new int*[size];
    for(int i = 0; i < size; i++){
        data[i] = new int[size];
        for(int j = 0; j < size; j++){
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}
};

int main(){
    matrix m(4);
    matrix m2(4);
    cout<<"Input Matrix 1"<<endl;
    cin>>m;
    cout<<"Input Matrix 2"<<endl;
    cin>>m2;
    
    cout<<m<<endl;
    cout<<m2<<endl;
      
matrix m3=m+m2;
cout<<"Add\n"<<m3<<endl;

matrix m4=m-m2;
cout<<"sub\n"<<m4<<endl;
matrix m5=m*m2;
cout<<"Product\n"<<m5<<endl;


if(m==m2){
    cout<<"\ntrue\n";
}
else{
    cout<<"\nfalse\n";
}

return 0;

}