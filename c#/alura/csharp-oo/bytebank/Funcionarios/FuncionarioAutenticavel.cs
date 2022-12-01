using bytebank.Funcionarios;
using bytebank.SistemaInterno;
using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank
{
    public abstract class FuncionacrioAutenticavel : Funcionario, IAutenticavel
    {
        protected FuncionacrioAutenticavel(string cpf, double salario):base(cpf, salario)
        {
        }

        public string Login { get ; set ; }
        public string Senha { get ; set ; }

        public bool Autenticar(string senha, string login)
        {
            return this.Senha == senha;
        }
    }
}