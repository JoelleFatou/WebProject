#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Student {
public:
    int studentID;
    string name;

    Student(int id, const string& n) : studentID(id), name(n) {}
};

class Club {
public:
    string name;
    unordered_set<int> members; // Store student IDs of members

    Club(const string& n) : name(n) {}

    void addMember(int studentID) {
        members.insert(studentID);
    }

    void removeMember(int studentID) {
        members.erase(studentID);
    }
};

class ClubHub {
public:
    unordered_map<int, Student> students;
    unordered_map<std::string, Club> clubs;
    unordered_map<int, unordered_set<int>> studentConnections; // Adjacency list for student connections

    void addStudent(int id, const string& name) {
        students[id] = Student(id, name);
        studentConnections[id] = {}; // Initialize connections for the new student
    }

    void addClub(const string& name) {
        clubs[name] = Club(name);
    }

    void addStudentToClub(int studentID, const string& clubName) {
        if (students.count(studentID) && clubs.count(clubName)) {
            Club& club = clubs[clubName];
            club.addMember(studentID);
            updateStudentConnections(studentID, club.members);
        } else {
            cout << "Error: Student or club not found." << std::endl;
        }
    }

    void removeStudentFromClub(int studentID, const string& clubName) {
        if (students.count(studentID) && clubs.count(clubName)) {
            Club& club = clubs[clubName];
            club.removeMember(studentID);
            updateStudentConnections(studentID, club.members, true); // Indicate removal
        } else {
            cout << "Error: Student or club not found." << endl;
        }
    }

    // Part b: Edges represent shared club memberships
    void updateStudentConnections(int studentID, const unordered_set<int>& clubMembers, bool isRemoval = false) {
        if (students.count(studentID)) {
            for (int memberID : clubMembers) {
                if (memberID != studentID) {
                    if (!isRemoval) {
                        studentConnections[studentID].insert(memberID);
                        studentConnections[memberID].insert(studentID);
                    } else {
                        studentConnections[studentID].erase(memberID);
                        studentConnections[memberID].erase(studentID);
                    }
                }
            }
        }
    }

    void displayConnections(int studentID) const {
        if (students.count(studentID)) {
            cout << "Connections (shared clubs) for student " << students.at(studentID).name << " (ID: " << studentID << "): ";
            for (int connectedID : studentConnections.at(studentID)) {
                cout << students.at(connectedID).name << " (ID: " << connectedID << ") ";
            }
            cout << endl;
        } else {
            cout << "Error: Student not found." << endl;
        }
    }
};

int main() {
    ClubHub hub;

    // Add some students
    hub.addStudent(1, "Alice");
    hub.addStudent(2, "Bob");
    hub.addStudent(3, "Charlie");
    hub.addStudent(4, "David");

    // Add some clubs
    hub.addClub("Coding Club");
    hub.addClub("Debate Society");

    // Add students to clubs
    hub.addStudentToClub(1, "Coding Club");
    hub.addStudentToClub(2, "Coding Club");
    hub.addStudentToClub(2, "Debate Society");
    hub.addStudentToClub(3, "Debate Society");

    // Now connections are automatically formed based on shared clubs

    // Display connections
    hub.displayConnections(1); // Should show Bob (from Coding Club)
    hub.displayConnections(2); // Should show Alice (from Coding Club) and Charlie (from Debate Society)
    hub.displayConnections(3); // Should show Bob (from Debate Society)

    // Remove a student from a club and see connections update
    hub.removeStudentFromClub(2, "Coding Club");
    cout << "\nAfter Bob leaves Coding Club:" << endl;
    hub.displayConnections(1); // Should now show no connections
    hub.displayConnections(2); // Should only show Charlie (from Debate Society)

    return 0;
}