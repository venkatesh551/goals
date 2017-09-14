template<class Scalar>
class complex {
    private:
    Scalar re, im;
    public:
        complex() :re{}, im{} {}
        template<typename T>
        complex(T rr, T ii =0) :re{rr}, im{ii} { }
        // default constructor
        complex(const complex&) = default;
        // copy constructor
        template<typename T>
        complex(const complex<T>& c) : re{c.real()}, im{c.imag()} { }

        Scalar real() const {
            return re;
        }
        Scalar imag() const {
            return im;
        }
};


int main()
{
    complex<float> cf;
    complex<double> cd(cf);

    return 0;
}
