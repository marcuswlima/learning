using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.Funcionarios
{
    public class Auxiliar : Funcionario
    {
        public int Funcao { get; set; }
        public Auxiliar(string cpf) : base(cpf, 2000)
        {

        }

        public override double GetBonificacao() //implementação específica que foi assinalada na classe base
        {
            return this.Salario * 0.2;
        }

        public override void AumentarSalario() //implementação específica que foi assinalada na classe base
        {
            this.Salario *= 1.1;
        }
    }

    public class Class1
    {
    }
}
