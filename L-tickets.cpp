#include <iostream>
#include <cstdint>

#define ZERO '0'

class BigInteger_t {

    public:
        std::string data_;
        BigInteger_t():
            data_("0") {}

        BigInteger_t(const std::string& new_string_data) {
            this->data_ = new_string_data;
        }

        BigInteger_t operator+(const BigInteger_t& cur) const {
            BigInteger_t result = *this;
            result += cur;
            return result;
        }

        void operator+=(const BigInteger_t& cur) {
            while (this->data_.length() < cur.data_.length()) this->data_.push_back(ZERO);

            unsigned int cur_len = this->data_.length(), act_len = cur.data_.length();
            unsigned int min_len = std::min(cur_len, act_len);

            bool shift = 0;
            for (unsigned int current_index = 0; current_index < min_len; ++current_index) {
                unsigned char current_char = data_[current_index] - ZERO;
                current_char += shift + (cur.data_[current_index] - ZERO);
                shift = !!(current_char / 10);
                data_[current_index] = (current_char % 10) + ZERO;
            }

            unsigned int current_index = min_len;
            for (; shift == true; ) {
                if (current_index == cur_len) data_.push_back(ZERO);

                unsigned char current_char = data_[current_index] - ZERO;
                current_char += shift;

                shift = !!(current_char / 10);
                data_[current_index++] = (current_char % 10) + ZERO;
            }
        }
};

// reverse order printing 
std::ostream& operator<<(std::ostream& stream, const BigInteger_t& cur) {
    for (ssize_t i = cur.data_.length() - 1; i >= 0; --i) stream << cur.data_[i];           
    return stream;
}

BigInteger_t** makeDynamic(size_t N, size_t M) {
    BigInteger_t** dynamic = new BigInteger_t*[N]();
    for (unsigned int act_len = 0; act_len < N; ++act_len) {
        dynamic[act_len] = new BigInteger_t[(act_len + 1) * M];
    }

    return dynamic;
}

void solve(size_t N, size_t M, BigInteger_t** dynamic) {
    for (unsigned int current_ticket = 0; current_ticket < M; ++current_ticket) {
        (*dynamic)[current_ticket] = {"1"};

        for (unsigned int next_ticket = 0; (next_ticket < M) && ((current_ticket + next_ticket) / 2 < M); ++next_ticket)
            dynamic[1][current_ticket + next_ticket] += (*dynamic)[current_ticket];
    }

    for (unsigned int act_len = 1; act_len < N - 1; ++act_len) {
        for (unsigned int current_ticket = 0; current_ticket < ((act_len + 1) * M); ++current_ticket) {
            for (unsigned int next_ticket = 0; (next_ticket < M) && ((current_ticket + next_ticket) < (act_len + 2) * M); ++next_ticket)
                dynamic[act_len + 1][current_ticket + next_ticket] += dynamic[act_len][current_ticket];
        }
    }
}

int main() {
    size_t N = 0, M = 0;
    std::cin >> N >> M;

    BigInteger_t** dynamic = makeDynamic(N, M);

    solve(N, M, dynamic);

    // dp rows formula, look at lines 74-80
    std::cout << dynamic[N - 1][(N / 2) * (M - 1)] << std::endl;

    for (unsigned int act_len = 0; act_len < N; ++act_len) delete[] dynamic[act_len];
    delete[] dynamic;
}