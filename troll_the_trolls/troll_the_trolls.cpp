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

bool permission_check(Action action, AccountStatus account) {
    if (account == AccountStatus::mod) {
        return true;
    } else if (account == AccountStatus::user || account == AccountStatus::troll) {

    }

    switch (account) {
        case AccountStatus::mod:
            return true;
        case AccountStatus::user:
        case AccountStatus::troll:
            switch (action) {
                case Action::read:
                case Action::write:
                    return true;        
                default:
                    return false;
            }
        case AccountStatus::guest:
            switch (action) {
                case Action::read:
                    return true;
                default:
                    return false;
            }
        default:
            return false; // or I should throw exception for any unexpected?
    }
}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.

void validate_AccountStatus(AccountStatus account) {
    switch (account) {
        case AccountStatus::guest:
        case AccountStatus::mod:
        case AccountStatus::troll:
        case AccountStatus::user:
            break;
        default:
            break; // throw error
    }
}

// combinations of the following return false, otherwise true: (guest, x), (troll, !troll)
bool valid_player_combination(AccountStatus player_1, AccountStatus player_2) {
    // check inputs are valid
    validate_AccountStatus(player_1);
    validate_AccountStatus(player_2);

    if (player_1 == AccountStatus::guest || player_2 == AccountStatus::guest) {
        return false;
    } else if ((player_1 == AccountStatus::troll && player_2 != AccountStatus::troll) ||
               (player_2 == AccountStatus::troll && player_1 != AccountStatus::troll)) {
        return false;
    } else {
        return true;
    }
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

bool has_priority(AccountStatus account_1, AccountStatus account_2) {
    // check inputs are valid
    validate_AccountStatus(account_1);
    validate_AccountStatus(account_2);

    switch (account_1) {
        case AccountStatus::mod:
            if (account_2 != AccountStatus::mod) {
                return true;
            } else {
                return false;
            }
        case AccountStatus::user:
            if (account_2 == AccountStatus::guest || account_2 == AccountStatus::troll) {
                return true;
            } else {
                return false;
            }
        case AccountStatus::guest:
            if (account_2 == AccountStatus::troll) {
                return true;
            } else {
                return false;
            }
        default: // troll accounts have no strictly higher priority
            return false;
    }
}

}  // namespace hellmath