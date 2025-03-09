//
// Created by bruno on 13/01/2025.
//

//Classe exemplo para os testes.

class DatabaseAPI_test : public DatabaseAPI {
public:
    //Aqui é feita a leitura do item e sua quantidade.
    std::vector<std::map<std::string, std::string>> read(const std::string& tableName) const override {
        return {
          { {"column1", "value1"}, {"column2", "value2"} },
          { {"column1", "value3"}, {"column2", "value4"} }
        };
    }
    //Aqui é feita a escrita dos dados, sobrepondo os dados que estariam nos elementos
    void write(const std::string& tableName, const std::vector<std::map<std::string, std::string>>& data) override {
        //Aqui é para colocar a linha que será alterada
        for (const auto& row : data) {
        //Este for é para fazer a "quebra" dos valores no data nas duas variáveis que ele armazena.
            for (const auto& [column, value] : row) {
                //fiquei na dúvida sobre esse cout, se preciso colocar ou não
                std::cout << "" << column << ": " << value << std::endl;
            }
        }
    }
};
