using bytebank.SistemaInterno;
using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.Funcionarios
{
    public class GerenteDeContas: FuncionacrioAutenticavel, IAutenticavel
    {
        public GerenteDeContas(string cpf) : base(cpf, 4000)
        {

        }

        public override double GetBonificacao()
        {
            return this.Salario * 0.25;
        }

        public override void AumentarSalario()
        {
            this.Salario *= 1.05;
        }

    }
}
