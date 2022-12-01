using bytebank.SistemaInterno;
using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.Funcionarios
{
    public class GerenteDeContas:Autenticavel
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

        public override bool Autenticar(string senha, string login)
        {
            return this.Senha==senha;
        }
    }
}
