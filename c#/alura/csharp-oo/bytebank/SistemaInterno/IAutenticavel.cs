using bytebank.Funcionarios;
using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.SistemaInterno
{
    public interface IAutenticavel 
    {
        public string Login { get; set; }
        public string Senha { get; set; }

        public abstract bool Autenticar(string senha, string login);

    }
}
