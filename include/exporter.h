//
// Created by Ondřej Bidlák on 09.12.2022.
//

#ifndef CPP_SP_01_EXPORTER_H
#define CPP_SP_01_EXPORTER_H

#include <filesystem>

typedef std::vector<std::vector<bool>> PgmData;
typedef std::vector<std::string> SvgData;
constexpr auto SVG_HEADER = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\r";
constexpr auto SVG_HEADER2 = "<svg width=\"100%\" height=\"100%\" viewBox=\"0 0 100 100\" xmlns=\"http://www.w3.org/2000/svg\">\r";

template<typename T>
class Exporter {
public:
    virtual void Export(std::string const &filename, T const &data) const = 0;
};

class SvgExporter : public Exporter<SvgData> {
public:
    void Export(std::string const &filename, SvgData const &data) const override;
};

class PgmExporter : public Exporter<PgmData> {
public:
    void Export(std::string const &filename, PgmData const &data) const override;
};


#endif //CPP_SP_01_EXPORTER_H
