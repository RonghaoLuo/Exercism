namespace targets {
// TODO: Insert the code for the alien class here
    class Alien {
        public:
            int x_coordinate = -1; // default -1 for error check
            int y_coordinate = -1;

            Alien(int x, int y) {
                x_coordinate = x;
                y_coordinate = y;
            }
            int get_health() {
                return health;
            }

            bool hit() {
                if (is_alive()) {
                    --health;
                }
                return true; // true if no shield, false if has shield
            }

            bool is_alive() {
                if (health > 0) {
                    return true;
                } else return false;
            }

            bool teleport(int x_new, int y_new) {
                x_coordinate = x_new;
                y_coordinate = y_new;
                return true;
            }

            bool collision_detection(Alien other_alien) {
                return x_coordinate == other_alien.x_coordinate && y_coordinate == other_alien.y_coordinate;
            }

        private:
            int health = 3;
    };
}  // namespace targets