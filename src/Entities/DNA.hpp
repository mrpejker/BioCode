#ifndef BioCode_Entities_DNA_hpp
#define BioCode_Entities_DNA_hpp

using namespace std;

enum class DNANucleotide {
  A = 0,
  T = 1,
  G = 2,
  C = 3
};

template< bool IsCyclic = false >
class DNA {
  using ntType = DNANucleotide;

  //! Flag that checked if it's cyclic acid
  constexpr static bool isCyclic_ = { IsCyclic };

  //! String itself represented as STL vector
  vector<ntType> nts_{ };
public:
  //! Construct acid from vector of nucleotides
  DNA(vector<ntType>&& nts) : nts_ { nts }
  {};

  //! Construct acid from string
  DNA(const string& dnaString) {
    for (const auto& symbol : dnaString) {
      switch (symbol) {
      case 'A': { nts_.push_back(ntType::A); break; };
      case 'T': { nts_.push_back(ntType::T); break; };
      case 'C': { nts_.push_back(ntType::C); break; };
      case 'G': { nts_.push_back(ntType::G); break; };
      default: { throw exception("Unexpected symbol in DNA string");  };
      };
    };
  };

  //! Convert to string
  operator string() const {
    string str{ };
    for (const auto& symbol : nts_) {
      switch (symbol) {
      case ntType::A: { str += 'A'; break; };
      case ntType::T: { str += 'T'; break; };
      case ntType::C: { str += 'C'; break; };
      case ntType::G: { str += 'G'; break; };
      };
    };
    return str;
  };
  
  //! Equality operator
  bool operator==(const DNA<IsCyclic> &other) const
  {
    if (other.size() != size()) return false;
    for (size_t i = 0; i < size(); i++) if (other[i] != nts_[i]) return false;
    return true;
  };

  //! Get size of acid string
  inline constexpr size_t size() const { return nts_.size(); };
  inline const vector<ntType>& data() const { return nts_; };

  //! Array type indexing
  inline const ntType& operator[](size_t i) const { return nts_[i]; };

  //! Array type slicing
  DNA slice(size_t startIndex, size_t lenght) const {
    vector<ntType> nts{ };
    for (auto i = startIndex; i < startIndex + lenght; i++) { nts.push_back(nts_[i]); };
    return DNA{ move(nts) };
  };

  //! Get complimentary
  inline constexpr ntType complementary(const ntType& nt) {
    return nt == ntType::A ? ntType::T : (nt == ntType::T ? ntType::A : (nt == ntType::G ? ntType::C : (nt == ntType::C ? ntType::G : throw exception(""))));
  };

  //! Get reverse complement of nucleotide string
  DNA<IsCyclic> reverse_complement() {
    vector<ntType> rc{ };
    for (auto it = rbegin(nts_); it != rend(nts_); it++) {
      rc.push_back(complementary(*it));
    };
    return std::move(rc);
  };
 
};


//Specify hash function for DNA string
//link : http://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
namespace std {

  template <typename SizeT>
  inline void hash_combine(SizeT& seed, SizeT value)
  {
    seed ^= value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }

  template <bool IsCyclic>
  struct hash<DNA<IsCyclic>>
  {
    //TO DO replace hash function to boost implementation for reliable properties
    size_t operator()(const DNA<IsCyclic>& k) const
    {
      size_t seed{ 0 };
      for (const auto& nt : k.data()) hash_combine(seed, static_cast<size_t>(nt));
      return seed;
    };
  };

}

#endif