import { Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { Usuario } from './entities/usuario.entity';
import { CreateUsuarioDto } from './dto/create-usuario.dto';
import * as bcrypt from 'bcryptjs';

@Injectable()
export class UsuarioService {
  constructor(
    @InjectRepository(Usuario)
    private usuarioRepository: Repository<Usuario>,
  ) {}

  async create(createUsuarioDto: CreateUsuarioDto) {
    // 1. Gera o "salt" (um valor aleatório para deixar a senha mais forte)
    const salt = await bcrypt.genSalt(10);
    
    // 2. Transforma a senha em texto puro num hash criptografado
    const hashSenha = await bcrypt.hash(createUsuarioDto.senha, salt);

    // 3. Cria o objeto do usuário substituindo a senha normal pela criptografada
    const novoUsuario = this.usuarioRepository.create({
      email: createUsuarioDto.email,
      senha: hashSenha,
    });

    // 4. Salva no banco de dados
    return this.usuarioRepository.save(novoUsuario);
  }

  // Já vamos deixar esse método pronto porque o Login (JWT) vai precisar dele depois!
  async findByEmail(email: string) {
    return this.usuarioRepository.findOne({ where: { email } });
  }
}