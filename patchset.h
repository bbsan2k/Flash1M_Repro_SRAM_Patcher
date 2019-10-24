#ifndef PATCHSET_H
#define PATCHSET_H

#include <vector>
#include <utility>
#include <string>


typedef struct
{
    std::vector< unsigned char > Marker;
    std::vector< unsigned char > Replace;
    std::vector< bool > MaskMarker;
    std::vector< bool > MaskReplace;
} Patch;

class PatchSet
{
public:
    PatchSet(std::string& identifier) { names = std::vector<std::string> {identifier}; };
    PatchSet(std::vector<std::string>& identifiers) { names = identifiers; };
    void addPatch(const std::vector<unsigned char>& marker, const std::vector<unsigned char>& replace, const std::vector<bool>& maskMarker = std::vector<bool>(), const std::vector<bool>& maskReplace = std::vector<bool>());
    std::vector< unsigned char > getIdentPattern() ;
    std::vector< Patch > getPatches() {return patches;};
    bool isApplicable(std::vector<unsigned char>& data, std::string* applicableName);
    void applyPatches(std::vector<unsigned char>* data);


private:
    int64_t findIndex(std::vector<unsigned char>* data, Patch* patch);

    std::vector<std::string> names;
    std::vector< Patch > patches;
};

#endif // PATCHSET_H
