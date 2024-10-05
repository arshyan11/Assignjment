#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    Node* get_head() {
        return head;
    }

    void insert(string val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) return;

        if (position == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) return;

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class Bignumber {
private:
    string value;

public:
    Bignumber(string val) {
        this->value = val;
    }
    
    LinkedList l1;

    void addvalue() {
        
            string v2;

            for (int j = 0; j < 1024; j++) {
                v2 += value[j];
                if ((j + 1) % 64 == 0) {
                    l1.insert(v2);
                    v2.clear();
                }
            }
        
    }

    bool isPrime(int num) {
        if (num <= 1) return false; // 0 and 1 are not prime
        if (num <= 3) return true; // 2 and 3 are prime
        if (num % 2 == 0 || num % 3 == 0) return false; // exclude multiples of 2 and 3
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }

    void checkEachPrimeNumbers() {
        Node* myhead = l1.get_head();
        Node* temp = myhead;
        string v3;

        while (temp != nullptr) { // Fix: should iterate till nullptr
            v3 += temp->data;
            temp = temp->next;
        }

        for (int i = 0; i < v3.length(); i++) {
            int number = v3[i] - '0'; // Convert char to int
            if (isPrime(number)) {
                cout << "Prime number: " << number << endl;
            }
        }
    }

    bool isWholePrime() {
        Node* myhead = l1.get_head();
        Node* temp = myhead;
        string v3;

        while (temp != nullptr) { // Fix: should iterate till nullptr
            v3 += temp->data;
            temp = temp->next;
        }

        if (v3.empty()) {
            cout << "No valid number to check primality." << endl;
            return false; // Return false or handle accordingly
        }

        try {
            long long num = stoll(v3); // Convert string to a long long
            return isPrime(num);
        } catch (const invalid_argument&) {
            cout << "Invalid argument for conversion to long long." << endl;
            return false;
        } catch (const out_of_range&) {
            cout << "Number is out of range for long long." << endl;
            return false;
        }
    }
};

int main() {
    // Example 1024-bit prime number (you can replace this with any valid 1024-bit prime number)
    Bignumber num("339733212740799292065380282176066971900658970696476753610473428782131200086007046665763640213662908765641248157467335887624779251845232797813270817598658305163990052439695903670953218603793482534272321596260506128150760772085576994144857032539374472637109916389490314364969634007140509798993163476100421201330176062731513756420277254312378166192124050870834217780215113853632631719025582601658355868230153899811328073904402141810047454180382486303533240805615051584353268001530304888119877225150546123480433329200626362613285317580900722540536784764222375598481456657152182288870083558046097812606365200027402081840005783020961792099988978309700051015630230632305138794600920615582227686857920844731733295657927370084328872657236676869804042233263453546143526813583418228471858473574550522351378918022797098537071508319127465143364889512774308660992606509775756328089782000706864133532950644872994216446751932496588362657290848007552059482512499145536181679731071962098088237035204242920436603334944198448420152968135051241673981192775737577390404942469109827474267425346395745999893505264444612417037883450221304202863918044185804424151202722017971134829900086075096782516482252733301500661195634064812984078870860556751197758437622406667522623974618164792391150419259891881849602907206731892211651203536934884378904698764862132583524814121448507828036100198575187226628350289371487677784576168199872571829166147144049144131891500168890905837853433535052822067060458370198556780151511950884416439570294906202550031888376585476358574159703095817989794911558962177706613016900422324434379335850517136809580785587076145836469282074006826597454634919839960884473702018020745084355906198835944064400219501075626036851721766909032090233493248740179049408760137862346722546907268982522968000485388125257592168406632121206295703433408048643636133235233794641180811348076217363113634942158382760401706135681637171554057882990339307845740522210964670001186124664962207992202120024019838053616425396309802684800682528697004964640226865862570291641329654350014401155052242035099615440803547920425180962972492106266968722314060632978593192966067034433444087436054064546592677930524820430258885266648556743375307802375004903967363330978134872427497520619894547003888230901429867942236783950102897191280828747476877116771264185946633287367201036719360989092420766653546157798991721679539532287213026919825843859771172835113209969188412264942188264444370127163837103024501043350885038870132528054276002364859343429840138105774878896292929552416295563262001798119993051661064306093706162831264858479682849016767691824097474077");
    num.addvalue();
    num.checkEachPrimeNumbers();
    num.isWholePrime();
}