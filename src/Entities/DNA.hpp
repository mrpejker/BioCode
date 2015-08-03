#ifndef BioCode_Entities_DNA_hpp
#define BioCode_Entities_DNA_hpp

enum DNANucleotide {
  A = 0,
  T = 1,
  G = 2,
  C = 3
};

template< bool IsCyclic = false >
class DNA {
  using ntType = DNANucleotide;

  //! List of complimentary pairs
  std::unordered_map<ntType, ntType> ntPairs_ {
      { ntType::A, ntType::T },
      { ntType::T, ntType::A }
  };

  //! Flag that checked if it's cyclic acid
  constexpr static bool isCyclic_ = { IsCyclic };

  //! String itself represented as STL vector
  std::vector<ntType> nts_{ };
public:
  //! Construct acid from vector of nucleotides
  DNA(std::vector<ntType>&& nts) : nts_ { nts }
  {};

  //! Construct acid from string
  DNA(const std::string& dnaString) {
    for (const auto& symbol : dnaString) {
      switch (symbol) {
      case 'A': { nts_.push_back(ntType::A); break; };
      case 'T': { nts_.push_back(ntType::T); break; };
      case 'C': { nts_.push_back(ntType::C); break; };
      case 'G': { nts_.push_back(ntType::G); break; };
      default: { throw std::exception("Unexpected symbol in DNA string");  };
      };
    };
  };

  //! Convert to string
  operator std::string() const {
    std::string str{ };
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

  //! Stream output operator


  //! Get size of acid string
  inline constexpr size_t size() const { return nts_.size(); };
  inline const std::vector<ntType>& data() const { return nts_; };

  //! Array type indexing
  inline const ntType& operator[](size_t i) const { return nts_[i]; };

  //! Array type slicing
  DNA slice(size_t startIndex, size_t lenght) const {
    std::vector<ntType> nts{ };
    for (auto i = startIndex; i < startIndex + lenght; i++) { nts.push_back(nts_[i]); };
    return DNA{ std::move(nts) };
  };

  //! Get complimentary
  inline constexpr ntType complementary(const ntType& nt) {
    return ntPairs_[nt];
  };

  //! Get reverse complimentary string
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
    std::size_t operator()(const DNA<IsCyclic>& k) const
    {
      using std::size_t;
      size_t seed{ 0 };
      for (const auto& nt : k.data()) hash_combine(seed, static_cast<size_t>(nt));
      return seed;
    };
  };

}

#endif