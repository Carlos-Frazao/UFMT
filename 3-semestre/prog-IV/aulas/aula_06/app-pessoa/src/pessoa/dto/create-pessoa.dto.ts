import { IsString, IsNumber, IsEmail, Min, Max } from 'class-validator';

export class CreatePessoaDto {
  @IsString({ message: 'Nome deve ser uma string' })
  nome: string;

  @IsNumber({}, { message: 'Idade deve ser um número' })
  @Min(0, { message: 'Idade não pode ser negativa' })
  @Max(150, { message: 'Idade não pode ser maior que 150' })
  idade: number;

  @IsEmail({}, { message: 'Email deve ser válido' })
  email: string;
}
