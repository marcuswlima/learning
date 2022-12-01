using bytebank.Funcionarios;
using bytebank.SistemaInterno;
using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.Titular
{
    public class Diretor:Autenticavel
    {
        public Diretor(string cpf) : base(cpf, 5000)
        {
            // Console.WriteLine("Criando um Diretor - derivada");

        }

        public override double GetBonificacao() //implementação específica que foi assinalada na classe base
        {
            return this.Salario * 0.5;
        }
          

        public override void AumentarSalario() //implementação específica que foi assinalada na classe base
        {
            this.Salario *=  1.15;
        }

        public override bool Autenticar(string senha, string login)
        {
            return this.Senha==senha;
        }
    }
}
