namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.

enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.

enum class Action {
    read,
    write,
    remove
};

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.

bool display_post(AccountStatus poster, AccountStatus viewer) {
    /*switch (poster)
    {
    case AccountStatus::mod:
        return true;
    case AccountStatus::user:
        
    
    default:
        break;
    }*/
    if (poster == AccountStatus::mod || poster == AccountStatus::user) { // posts by mod and user can be seen by everyone
        return true;
    } else if (poster == AccountStatus::troll && viewer == AccountStatus::troll) { // posts by trolls can only be seen by trolls
        return true;
    } else if (poster == AccountStatus::troll && viewer != AccountStatus::troll) {
        return false;
    } else {
        return false; // guest can't have posts, so no if statement for guest as poster
    }
    /*
    if (poster == AccountStatus::troll && viewer != AccountStatus::troll) {
        return false;
    } else {
        return true;
    } */ // posts by trolls are only seen by trolls
}

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.


}  // namespace hellmath