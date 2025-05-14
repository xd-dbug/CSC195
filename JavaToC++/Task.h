#include <string>
#include <sstream>
using namespace std;

class Task {
private:
    static int idCounter; 
    int id;
    string title;
    string description;
    string assignedTo;
    string status;

public:
    Task(string title, string description, string assignedTo);

    int getId() const;
    string getTitle() const;
    string getDescription() const;
    string getAssignedTo() const;
    string getStatus() const;

    void setTitle(string title);
    void setDescription(string description);
    void setAssignedTo(string assignedTo);
    void setStatus(string status);

    string toString() const;
};


