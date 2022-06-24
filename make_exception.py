hpp_filename = "exception.hpp"


class exception_template:

    def __init__(self, _Info: dict):
        self.name = _Info['name'].strip()
        self.code = _Info['code']
        self.mes = _Info['mes'].strip()
        self.define_code = "SDYZ_" + self.name.upper() + "_CODE"
        self.define_mes = "SDYZ_" + self.name.upper() + "_MESSAGE"
        #self.name = self.name.replace('_', '')

    # 创建声明及定义
    def make_exception_hpp(self):
        s = '''
class {name} : public sdyz::base_exception
{{
public:
#define {d_c_name} {code}
#define {d_m_name} \"{mes}\"

    {name}() : base_exception({d_c_name}, {d_m_name})
    {{
    }}

    {name} (const char* _Position) : base_exception({d_c_name}, {d_m_name}, _Position)
    {{
    }}

    ~{name}()
    {{
    }}

}};
'''.format(d_c_name=self.define_code, d_m_name=self.define_mes, name=self.name, code=self.code, mes=self.mes)
        return s


class ExceptPack_maker:
    def __init__(self, _exception_info_file: str = "exception.info"):
        self.exception_info_file = _exception_info_file
        self.include_header_file_list = ['base_exception.hpp']
        self.read_exception_info()

    def read_exception_info(self):
        with open(self.exception_info_file, "r", encoding="gbk") as f:
            info_list = f.readlines()
            info_dict_list = []
            for info in info_list:
                if (not info.startswith("#") and info.strip() != "" ):
                    info_dict_list.append(eval(info))
        self.info_dict_list = info_dict_list[:]

    def make_hpp_file(self):
        with open(hpp_filename, "w", encoding="gbk") as f:
            res = "#pragma once\n"
            for i in self.include_header_file_list:
                header_str = "#include \"{s}\"\n".format(s=i)
                res = res + header_str

            for i in self.info_dict_list:
                exc = exception_template(i)
                res = res + exc.make_exception_hpp()
            print(res, file=f)


if __name__ == "__main__":
    mker = ExceptPack_maker()
    mker.make_hpp_file()
