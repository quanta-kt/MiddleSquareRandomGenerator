namespace middlesquare {

    class Generator {
        public:

        /** Create a Generator object with given seed */
        Generator(const int seed);

        /** Gets next number from the generator */
        int next();

        private:
        void invalidate_seed();
        int seed;
    };

    int pad(const int source, const int digits);
}