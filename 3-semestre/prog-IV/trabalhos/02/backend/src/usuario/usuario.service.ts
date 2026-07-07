import { ConflictException, Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import * as bcrypt from 'bcryptjs';
import { Repository } from 'typeorm';
import { CreateUsuarioDto } from './dto/create-usuario.dto';
import { Usuario } from './entities/usuario.entity';

@Injectable()
export class UsuarioService {
  constructor(
    @InjectRepository(Usuario)
    private readonly usuarioRepository: Repository<Usuario>,
  ) {}

  async create(createUsuarioDto: CreateUsuarioDto) {
    const usuarioExistente = await this.findByEmail(createUsuarioDto.email);

    if (usuarioExistente) {
      throw new ConflictException('E-mail ja cadastrado');
    }

    const senha = await bcrypt.hash(createUsuarioDto.senha, 10);
    const usuario = this.usuarioRepository.create({
      email: createUsuarioDto.email,
      senha,
    });

    const usuarioSalvo = await this.usuarioRepository.save(usuario);
    return {
      id: usuarioSalvo.id,
      email: usuarioSalvo.email,
    };
  }

  findByEmail(email: string) {
    return this.usuarioRepository.findOne({ where: { email } });
  }
}
