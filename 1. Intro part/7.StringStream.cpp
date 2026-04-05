> assume some one give inut this way
 Amarla 21 20000 
 Rounak 22 35000 
 so on ... 
here name age and account bakalnce need to take in cpp using create a own class of that howto take input?

basically trying to map structured input → object → store/use.
class Person {
public:
    string name;
    int age;
    int balance;
    void input() { cin >> name >> age >> balance; }
    void display() { cout << name << " " << age << " " << balance << endl; }
};
int main() {
    int n;
    cin >> n;
    vector<Person> people(n);
    for(int i = 0; i < n; i++) {
        people[i].input();
    }
    for(auto &p : people) {
        p.display();
    }
}

> Using stringstream is better when:

Input comes line by line
Names may or may not have spaces
You want cleaner parsing logic

But you need to use it correctly, otherwise you’ll still hit edge cases.

class Person {
public:
    string name;
    int age;
    int balance;

    void input() {
        string line;
        getline(cin, line); // take full line
        stringstream ss(line);
        ss >> name >> age >> balance;
    }
    void display() {
        cout << name << " " << age << " " << balance << endl;
    }
};

int main() {
    int n = 2; // or take from input
    vector<Person> people(n);
    cin.ignore();
    for(int i = 0; i < n; i++) { people[i].input(); }
    for(auto &p : people) { p.display(); }
    return 0;
}