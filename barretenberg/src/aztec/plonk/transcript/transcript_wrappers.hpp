#pragma once

#include "./transcript.hpp"
#include <ecc/curves/bn254/fr.hpp>
#include <ecc/curves/bn254/g1.hpp>

namespace transcript {
class StandardTranscript : public Transcript {
  public:
    StandardTranscript(const Manifest input_manifest,
                       const HashType hash_type = HashType::Keccak256,
                       const size_t challenge_bytes = 32)
        : Transcript(input_manifest, hash_type, challenge_bytes)
    {}

    StandardTranscript(const std::vector<uint8_t>& input_transcript,
                       const Manifest input_manifest,
                       const HashType hash_type = HashType::Keccak256,
                       const size_t challenge_bytes = 32)
        : Transcript(input_transcript, input_manifest, hash_type, challenge_bytes){};

    void add_field_element(const std::string& element_name, const barretenberg::fr& element);

    barretenberg::fr get_field_element(const std::string& element_name) const;
    barretenberg::g1::affine_element get_group_element(const std::string& element_name) const;

    std::vector<barretenberg::fr> get_field_element_vector(const std::string& element_name) const;

    barretenberg::fr get_challenge_field_element(const std::string& challenge_name, const size_t idx = 0) const;
    barretenberg::fr get_challenge_field_element_from_map(const std::string& challenge_name,
                                                          const std::string& challenge_map_name) const;

    std::vector<uint8_t> export_transcript() const { return Transcript::export_transcript(); }
};

} // namespace transcript
