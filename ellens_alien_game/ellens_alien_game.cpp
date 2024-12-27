namespace targets {
// TODO: Insert the code for the alien class here
    class Alien {
        public:
            int x_cordinate = -1; // default -1 for error check
            int y_cordinate = -1;

            Alien(int x, int y) {
                x_cordinate = x;
                y_cordinate = y;
            }
            int get_health() {
                return health;
            }

        private:
            int health = 3;
    };
}  // namespace targets