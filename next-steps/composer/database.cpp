#include <algorithm>
#include "database.h"

Database::Database() : next_slot_(0) {}
Database::~Database() {}

// Add a new composer using operations in the Composer class.
// For convenience, we return a reference (pointer) to the new record.
Composer& Database::AddComposer(string in_first_name, string in_last_name, string in_genre, int in_yob, string in_fact) {
    int current_slot = next_slot_;
    composers_[current_slot].set_first_name(in_first_name);
    composers_[current_slot].set_last_name(in_last_name);
    composers_[current_slot].set_composer_genre(in_genre);
    composers_[current_slot].set_composer_yob(in_yob);
    composers_[current_slot].set_fact(in_fact);
    next_slot_++;
    return composers_[current_slot];
}

// Search for a composer based on last name. Return a reference to the
// found record.
Composer& Database::GetComposer(string in_last_name) {
    for (int i = 0; i < next_slot_; i++) {
        if (composers_[i].last_name() == in_last_name)
            return composers_[i];
    }
    return composers_[next_slot_];
}

// Display all composers in the database.
void Database::DisplayAll() {
    for (int i = 0; i < next_slot_; i++) 
        composers_[i].Display();
}

// Sort database records by rank and then display all.
void Database::DisplayByRank() {
    sort(composers_, composers_ + next_slot_, [](Composer &lhs, Composer &rhs){return lhs.ranking() < rhs.ranking();});
    DisplayAll();
}

