namespace middlesquare {

    class Generator {
        public:

        /** Create a Generator object with given seed */
        Generator(const int seed);

        /** Gets next number from the generator */
        int next();

        private:
        int seed;
    };

    int trim_middle(const int source, const int to_digits);
}