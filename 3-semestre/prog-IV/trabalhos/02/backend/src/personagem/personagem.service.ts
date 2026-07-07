import { Injectable, NotFoundException, OnModuleInit } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { CreatePersonagemDto } from './dto/create-personagem.dto';
import { UpdatePersonagemDto } from './dto/update-personagem.dto';
import { Personagem } from './entities/personagem.entity';
import { personagensSeed } from './personagens.seed';

@Injectable()
export class PersonagemService implements OnModuleInit {
  constructor(
    @InjectRepository(Personagem)
    private readonly personagemRepository: Repository<Personagem>,
  ) {}

  async onModuleInit() {
    const total = await this.personagemRepository.count();

    if (total === 0) {
      await this.personagemRepository.save(personagensSeed);
    }
  }

  create(createPersonagemDto: CreatePersonagemDto) {
    const personagem = this.personagemRepository.create(createPersonagemDto);
    return this.personagemRepository.save(personagem);
  }

  findAll() {
    return this.personagemRepository.find({ order: { ordem: 'ASC' } });
  }

  async findOne(id: number) {
    const personagem = await this.personagemRepository.findOneBy({ id });

    if (!personagem) {
      throw new NotFoundException('Personagem nao encontrado');
    }

    return personagem;
  }

  async update(id: number, updatePersonagemDto: UpdatePersonagemDto) {
    const personagem = await this.findOne(id);
    Object.assign(personagem, updatePersonagemDto);
    return this.personagemRepository.save(personagem);
  }

  async remove(id: number) {
    const personagem = await this.findOne(id);
    await this.personagemRepository.remove(personagem);
    return { mensagem: 'Personagem removido com sucesso' };
  }
}
